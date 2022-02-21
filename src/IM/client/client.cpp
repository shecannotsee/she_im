#include "../base.h"

std::mutex door;
char receivce_buffer[1024];
char send_____buffer[1024];
char error_;

void receive_information(const int& client_socket_id)
{
  while(1){
    //door.lock();
	memset(receivce_buffer,0x00,sizeof(char)*1024);
    read(client_socket_id,receivce_buffer,1024);
	std::cout<<"Get from server:>";
	std::cout<<receivce_buffer<<std::endl;
    //door.unlock();
  }
}
void send_information(const int& client_socket_id)
{
  while(1){
    //door.lock();
	memset(send_____buffer,0x00,sizeof(char)*1024);
	std::cin>>send_____buffer;
	write(client_socket_id,send_____buffer,1024);
	std::cout<<"Send:>";
	std::cout<<send_____buffer<<std::endl;
    //door.unlock();
  }
}

int main()
{
  //1.创建套接字
  int client_socket_id = socket(AF_INET, SOCK_STREAM, 0);
  if( client_socket_id == -1 ){
    std::cout<<"Create socket failed."<<std::endl;
	std::cin>>error_;
  }
  //2.设置服务器信息（ip port）
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));//初始化
  server_address.sin_family = AF_INET;  //使用IPv4地址
  server_address.sin_addr.s_addr = inet_addr(SERVER_IP);  //服务器IP
  server_address.sin_port = htons(PORT);  //端口、
  //3.连接服务器
  if( connect(client_socket_id, (struct sockaddr*)&server_address, sizeof(server_address)) == -1 ){
    std::cout<<"Connect server failed."<<std::endl;
	std::cin>>error_;
  }else{
	std::cout<<"Connect server success."<<std::endl;
  }
  //4.多线程进行读写
  std::thread twrite(receive_information,client_socket_id);
  std::thread tread(send_information,client_socket_id);
  twrite.join();
  tread.join();

  close(client_socket_id);
  return 0;
}
