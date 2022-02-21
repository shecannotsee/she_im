#ifndef __RW_H_
#define __RW_H_

#include <string>
#include <vector>

namespace rw
{
  void createTableSttFile(const std::string&);
  void createTableDataFile(const std::string&);
  void writeSttInSttFile(
      const std::vector<std::string>&/*name*/,
      const std::vector<std::string>&/*type*/,
      const std::vector<int>&/*length*/
  );
  
  void readTableStt(
      const std::string&/*table name*/,
      std::vector<std::string>&/*name*/,
      std::vector<std::string>&/*type*/,
      std::vector<int>&/*length*/
  );

  void writeDataIntoDataFile(const std::vector<std::string>&);
  void deleteData(const std::vector<std::string>&);
  std::vector< std::vector<std::string> > searchData(const std::vector<std::string>&);

};

#endif//!__RW_H_