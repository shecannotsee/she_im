#include <fstream>

int main()
{
    std::ofstream tableStt;
    std::ofstream tableData;
    tableStt.open("test_structure.stt", std::ios::out | std::ios::ate );//在末尾写入
    tableData.open("test_data_1.dat", std::ios::out | std::ios::ate );//在末尾写入

    tableStt<<"20"<<std::endl;
    tableStt<<20<<std::endl;

    tableStt.close();
    tableData.close();

    return 0;
}
