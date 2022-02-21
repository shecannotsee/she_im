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
	std::cout<<"Get from Client:>";
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
  //1.创建socket
  int server_socket_id=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if( server_socket_id == -1 ){
    std::cout<<"Create socket failed."<<std::endl;
	std::cin>>error_;
  }
  //2.socket与通讯地址绑定绑定
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));  //每个字节都用0填充
  server_address.sin_family = AF_INET;  //使用IPv4地址
  server_address.sin_addr.s_addr = inet_addr("0.0.0.0");  //具体的IP地址
  server_address.sin_port = htons(PORT);  //端口
  if( bind( 
	    server_socket_id, 
		(struct sockaddr*)&server_address, 
		sizeof(server_address)
	  ) == -1 ){
	std::cout<<"socket and Address binding failed."<<std::endl;
	std::cin>>error_;
  }
  //3.服务器开始监听
  if( listen(server_socket_id,LISTEN_BACK_LOG) == -1){
	std::cout<<"Listen failed."<<std::endl;
	std::cin>>error_;
  }else{
	std::cout<<"Start to listen......"<<std::endl;
  }
  //4.接收客户端请求
  struct sockaddr_in client_address;
  socklen_t client_address_size = sizeof(client_address);
  int client_socket_id = accept(
	server_socket_id, 
	(struct sockaddr*)&client_address, 
	&client_address_size
  );
  if(client_socket_id==-1){
    std::cout<<"Accept to client failed."<<std::endl;
	std::cin>>error_;
  }else{
    std::cout<<"Accept to client success."<<std::endl;
  }
  //5.进行收发信息
  std::thread twrite(receive_information,client_socket_id);
  std::thread tread(send_information,client_socket_id);
  twrite.join();
  tread.join();


  close(client_socket_id);
  close(server_socket_id);
  return 0;
}