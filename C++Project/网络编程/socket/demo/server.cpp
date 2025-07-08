#include <iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<cstring>
#include<string>
#include <unistd.h>
#include <arpa/inet.h>
int main()
{
    //创建socket(AF_INET:ipv4 SOCK_STREAM:（面向连接）TCP IPPROTO_TCP确定使用TCP)
    int sockfd=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    //创建成功返回 0 创建失败返回 1
    if(sockfd<0)
    {
        //打印错误字符和错误信息
        printf("socket error:errno=%d errmsg=%s",errno,strerror(errno));
        return 1;
    }
    else
    {
        printf("socket success\n");

    }
    //绑定socket
    std::string ip="127.0.0.1";//添加地址
    int port=8080;//添加端口
    struct sockaddr_in sockaddr;
    std::memset(&sockaddr,0,sizeof(sockaddr));//成员全部清零
    sockaddr.sin_family=AF_INET;//使用ipv4
    sockaddr.sin_addr.s_addr=inet_addr(ip.c_str());//绑定回环地址
    sockaddr.sin_port=htons(port);//绑定端口
    if(::bind(sockfd,(struct sockaddr*)&sockaddr,sizeof(sockaddr))<0)
    {
        printf("bind error:errno=%d errmsg=%s\n",errno,strerror(errno));
        return 1;
    }
    else
    {
        printf("bind success\n");

    }
    //监听 socket
    if(::listen(sockfd,1024)<0)//监听socket 和字符长度
    {
        printf("listen error:errno=%d errmsg=%s\n",errno,strerror(errno));
        return 1;
    }
    else
    {
        printf("listening......\n");

    }
    //接收客户端的连接
    while(true)
    {
        int connfd=::accept(sockfd,nullptr,nullptr);
        if(connfd<0)
        {
            printf("accept error:errno=%d errmsg=%s \n",errno,strerror(errno));
            return 1;
        }
        char buf[1024]={0};
        //接收客户端的数据
        size_t len=::recv(connfd,buf,sizeof(buf),0);
        printf("recv connfd=%d msg=%s \n",connfd,buf);
        //向客户端发送数据
        ::send(connfd,buf,sizeof(buf),0);
    }
    //关闭socket
    ::close(sockfd);
}

//水一下
