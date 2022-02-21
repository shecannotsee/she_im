#ifndef __SHESQL_H_
#define __SHESQL_H_

#include "base.h"
#include "rw/rw.h"
#include <iostream>
#include <string>
#include <vector>

class shesql
{
private:
  /* data */
public:
  shesql(/* args */);
  virtual ~shesql();

public:
  int createTable(const std::string&,const std::string&);
  int getTableStt(const std::string&);
  int insertData(const std::vector<std::string>&);
  int deleteData(const std::vector<std::string>&);
  std::vector< std::vector<std::string> > searchData(const std::vector<std::string>&);

private:
  std::vector<std::string> m_table_stt_name;
  std::vector<std::string> m_table_stt_type;
  std::vector<int> m_table_stt_length;
};

#endif//!__SHESQL_H_
