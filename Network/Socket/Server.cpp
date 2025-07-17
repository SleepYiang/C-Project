#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
int main()
{
  //创建socket
  int sockfd=socket(AF_INET,SOCK_STREAM,0);
  if(sockfd<0)
    printf("socket creation failed :errno = %d errmsg=%s",errno,strerror(errno));
  else
    printf("socket successfully created");
  //绑定socket
  std::string ip="127.0.0.1";
  int port=8080;
  struct sockaddr_in server;
  std::memset(&server,0,sizeof(server));
  server.sin_family=AF_INET;
  server.sin_port=htons(port);
  server.sin_addr.s_addr=inet_addr(ip.c_str());
  if (bind(sockfd,(struct sockaddr*)&server,sizeof(server))<0)
  {
    printf("socket bind failed :errno = %d errmsg=%s",errno,strerror(errno));
    return -1;
  }
  else
  {
    printf("socket successfully binded");
  }
  //监听socket
  if (listen(sockfd,5)<0)
  {
    printf("socket listen failed :errno = %d errmsg=%s",errno,strerror(errno));
  }else
  {
    printf("socket successfully listening");
  }
  while (true)
  {
    //接收客户端的连接
    int connfd=accept(sockfd,nullptr,nullptr);
    if(connfd<0)
    {
      printf("accept failed :errno = %d errmsg=%s",errno,strerror(errno));
      return 1;
    }
   char buf[1024]={0};
    //接收客户端的数据
    size_t len=recv(connfd,buf,sizeof(buf),0);
    printf("recv: connfd=%d msg=%s",connfd,buf);

    //向客户端发送数据
    send(connfd,buf,sizeof(buf),0);
  }
  //关闭套接字
  close(sockfd);
  return 0;
}