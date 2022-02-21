#include "shesql.h"

shesql::shesql()
{

};

shesql::~shesql()
{

}


int shesql::createTable(const std::string& tableName,const std::string& tableStt)
{
  //1.将tableStt的信息解析到m_table_stt_name，m_table_stt_type，m_table_stt_length中
  //后续需要将该步骤改写为私有函数
  std::string temp = "";
  int flag = 0;//name-type-length
  int length = 0;
  for( int i=0; i<tableStt.size(); i++ ){
    if(tableStt[i]=='-'){
        if( flag == 0 ){
            m_table_stt_name.push_back(temp);//name
            flag++;
            temp = "";
        }else if( flag == 1 ){
            m_table_stt_type.push_back(temp);//type
            flag++;
            temp = "";
        }
    }else if( tableStt[i]==',' || i==tableStt.size()-1 ){
        if( i==tableStt.size()-1 ) temp+=tableStt[i];
        if( flag==2 ){
            for( int j=0; j<temp.size(); j++ ){
                length *= 10;
                length += temp[j] - '0';
            }
            m_table_stt_length.push_back(length);//length
            length = 0;
            flag = 0;
            temp = "";
        }

    }else{
        temp+=tableStt[i];
    }
  }
  temp = "";
  //2.创建表结构文件
  rw::createTableSttFile(tableName);
  //3.创建表数据文件
  rw::createTableDataFile(tableName);
  //4.将表结构写入表结构文件中
#ifdef __SHE_TEST_

#endif//!__SHE_TEST_
  rw::writeSttInSttFile(
    m_table_stt_name,
    m_table_stt_type,
    m_table_stt_length);

  return CREATE_TABLE_SUCCESS;
};

int shesql::getTableStt(const std::string& tableName)
{
#ifdef __SHE_TEST_
  std::cout<<"Get the table structure.";
  std::cout<<VNAME(tableName)<<":"<<tableName;
  std::cout<<std::endl;
#endif//!__SHE_TEST

  //1.从表结构文件中读取表结构存入类中
  rw::readTableStt(
    tableName,
    this->m_table_stt_name,
    this->m_table_stt_type,
    this->m_table_stt_length);

#ifdef __SHE_TEST_
  std::cout<<"Read the table structure success."<<std::endl;
  std::cout<<"name(type):length"<<std::endl;
  for( int i=0; i<m_table_stt_name.size(); i++ ){
    std::cout<<m_table_stt_name[i]<<"("<<m_table_stt_type[i]<<"):"<<m_table_stt_length[i];
    std::cout<<std::endl;
  }
  std::cout<<"Play table structure over."<<std::endl;
#endif//！__SHE_TEST_

  return GET_TABLE_STT_SUCCESS;
};

int shesql::insertData(const std::vector<std::string>& condition)
{
  //1.检查数据是否符合规则
  std::cout<<"Insert check!"<<std::endl;
  //2.将数据进行插入
  rw::writeDataIntoDataFile(condition);
  //3.检查插入是否成功，返回结果
  return INSERT_DATA_SUCCESS;
};

int shesql::deleteData(const std::vector<std::string>& condition)
{
  //1.检查数据是否符合规则
  std::cout<<"Delete check!"<<std::endl;
  //2.将数据进行删除操作
  rw::deleteData(condition);
  //3.返回成功
  return DELETE_DATA_SUCCESS;
};

std::vector< std::vector<std::string> >  
shesql::searchData(const std::vector<std::string>& condition)
{
  //1.检查数据（查询条件）是否合法
  std::cout<<"Search check!"<<std::endl;
  //2.读出符合条件的数据
  return rw::searchData(condition);
};
