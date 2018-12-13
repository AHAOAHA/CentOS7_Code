/*************************************************************************
*File Name: service.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Thu 13 Dec 2018 07:33:25 PM CST
 ************************************************************************/
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

int main()
{
  int n;
  char buf[1024];
  char addr_p[INET_ADDRSTRLEN];
  struct sockaddr_in cin;
  socklen_t len;
  //创建套接字
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(-1 == sockfd)
  {
    perror("sockfd error ...");
    exit(EXIT_FAILURE);
  }

  //bind将套接字将ip地址和端口号绑定起来
  struct sockaddr_in s_add;
  bzero(&s_add, sizeof(s_add));
  s_add.sin_family = AF_INET;
  s_add.sin_addr.s_addr = htonl(INADDR_ANY);

  s_add.sin_port = htons(0x8080);

  int ret = bind(sockfd, (struct sockaddr*)&s_add, sizeof(struct sockaddr));
  if(-1 == ret)
  {
    perror("bind error ...");
    exit(EXIT_FAILURE);
  }
  
  //服务器监听客户端
  int listen_ret = listen(sockfd, 5);
  if(-1 == listen_ret)
  {
    perror("listen error ...");
    exit(EXIT_FAILURE);
  }
  printf("please wait ...\n");
  while(1)
  {
    //接受连接请求
    int accept_ret = accept(sockfd, (struct sockaddr*)&cin, &len);
    if(-1 == accept_ret)
    {
      perror("accept error ...");
      exit(EXIT_FAILURE);
    }
    printf("connect success ...\n");
    while(1);
    int recv_ret = recv(sockfd, buf, 1024, 0);
    if(-1 == recv_ret)
    {
      perror("recv error ...");
      exit(EXIT_FAILURE);
    }
    else if(0 == recv_ret)
    {
      printf("the connect has been closed ...\n");
      close(sockfd);
      continue;
    }
    
    /*
    //将客户端地址转换为字符串
    inet_ntop(AF_INET, &cin.sin_addr, addr_p, sizeof(addr_p));
    printf("client addr is %s ... port is %s ...\n", addr_p, ntohs(cin.sin_port));
    printf("connect is %s ...\n", buf);
    n = strlen(buf);
    sprintf(buf, "%d", n);

    n = send(sockfd, buf, sizeof(buf) + 1, 0);
    if(-1 == n)
    {
      perror("send error ...");
      exit(EXIT_FAILURE);
    }
    
    n = close(sockfd);
    if(-1 == n)
    {
      perror("close error ...");
      exit(EXIT_FAILURE);
    }
    */
    close(sockfd);
  }
  return 0;
}
