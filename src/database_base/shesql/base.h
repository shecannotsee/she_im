#ifndef __BASE_H_
#define __BASE_H_
//#define __SHE_TEST_//DEBUG
#ifdef __SHE_TEST_
#define VNAME(value) (#value)
#endif//!__SHE_TEST_

//创建表的返回信息
enum {
  FAIL                    = 0,    //0-通用失败
  SUCCESS                 ,       //1-通用成功

  CREATE_TABLE_FAIL       ,       //2-创建表失败
  CREATE_TABLE_SUCCESS    ,       //3-创建表成功

  GET_TABLE_STT_FAIL      ,       //4-获取表结构成功
  GET_TABLE_STT_SUCCESS   ,       //5-获取表结构失败

  INSERT_DATA_FAIL        ,       //6-插入数据失败
  INSERT_DATA_SUCCESS     ,       //7-插入数据成功

  DELETE_DATA_FAIL        ,       //8-删除数据失败
  DELETE_DATA_SUCCESS     ,       //9-删除数据成功

};


#endif  //!__BASE_H_