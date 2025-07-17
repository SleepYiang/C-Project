#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
int main()
{
  //创建socket
  int sockfd=socket(AF_INET,SOCK_STREAM,0);
  if(sockfd==-1)
  {
    printf("socket creation failed :errno = %d errmsg=%s",errno,strerror(errno));
  }else
  {
    printf("socket successfully created");
  }
  //连接socket
  std::string ip="127.0.0.1";
  int port=8080;
  struct sockaddr_in client;
  memset(&client,0,sizeof(client));
  client.sin_family=AF_INET;
  client.sin_port=htons(port);
  client.sin_addr.s_addr=inet_addr(ip.c_str());
  if(connect(sockfd,(struct sockaddr*)&client,sizeof(client))<0)
  {
    printf("connect failed :errno = %d errmsg=%s",errno,strerror(errno));
    return 1;
  }
  //发送消息
  std::string data="hello world";
  send(sockfd,data.c_str(),data.size(),0);
  //接收消息
  char recvbuf[1024];
  recv(sockfd,recvbuf,sizeof(recvbuf),0);
  close(sockfd);
  return 0;
}