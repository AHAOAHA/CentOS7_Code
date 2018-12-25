/*************************************************************************
*File Name: service.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Tue 25 Dec 2018 02:50:32 PM CST
 ************************************************************************/
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main()
{
  //创建套接字
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd == -1)
  {
    perror("socket error ...\n");
    exit(-1);
  }

  //定义sockaddr_in结构体
  struct sockaddr_in sockaddr;
  bzero(&sockaddr, sizeof(sockaddr));
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port = htons(0x8080);
  sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  //绑定sockfd和sockaddr_in
  int bindret = bind(sockfd, (struct sockaddr*)&sockaddr, sizeof(sockaddr));
  if(bindret == -1)
  {
    perror("bind error ...\n");
    exit(-1);
  }

  //开始监听
  int listenret = listen(sockfd, 5);
  if(listenret == -1)
  {
    perror("listen error ...\n");
    exit(-1);
  }

  //保存客户端信息
  struct sockaddr_in clientaddr;
  char buf[1024];
  socklen_t lenth = sizeof(clientaddr);

  //开始处理请求
  while(1)
  {
    int clientfd = accept(sockfd, (struct sockaddr*)&clientaddr, &lenth);
    if(0 > clientfd)
    {
      perror("accept error ...\n");
      exit(-1);
    }
    printf("connected\n");

    memset(buf, 0, sizeof(buf));

    int len = recv(clientfd, buf, sizeof(buf), 0);
    fputs(buf, stdout);

    //http_send(clientfd, "hello world!\n");
    close(clientfd);
  }

  return 0;
}
