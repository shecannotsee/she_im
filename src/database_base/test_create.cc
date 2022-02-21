/**
 * 创建表测试
 * 
 * 创建日期：2022-01-03
 * 作者：shecannotsee
 * 
 * 
 */

int main()
{
    //shesql IMmessage;

    //创建用户信息表user
    //主键ID，昵称，序列号长ID，密码，创建时间
    //IMmessage.createTable(\"user",\
        "\
        ID-int-32,\
        name-string-30,\
        realID-int-32,\
        password-string-20,\
        createTime-int-32,\
        ");

    //创建通讯详细信息表information
    //主键ID，使用序列号长ID，
    //  传输信息类型，传输信息的方向(SEND和RECEIVE)，传输信息目标，
    //  传输信息时间，传输信息内容
    //IMmessage.createTable(\"information",\
        "\
        ID-int-32,\
        realID-int-32,\
        TYPE-int-32,\
        send_and_receive-int-32,\
        target-int-32,\
        time-int-32,\
        content-string-32,\
        ");

    //插入数据

    //查询数据

    //删除数据



    return 0;
}