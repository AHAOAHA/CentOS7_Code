/*************************************************************************
*File Name: client.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Thu Dec 13 20:35:13 2018
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
  struct sockaddr_in c_add;
  //创建套接字
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(-1 == sockfd)
  {
    perror("socket error ...");
    exit(EXIT_FAILURE);
  }

  bzero(&c_add, sizeof(c_add));
  c_add.sin_family = AF_INET;
  c_add.sin_port = htons(8000);
  c_add.sin_addr.s_addr = inet_addr("39.108.94.7");
  //if(-1 == ret)
  //{
  //  perror("inet_pton error ...");
  //  close(sockfd);
  //  exit(EXIT_FAILURE);
  //}
  printf("wait ...\n");
  int con_ret = connect(sockfd, (struct sockaddr*)&c_add, sizeof(c_add));
  if(-1 == con_ret)
  {
    perror("connect error ...");
    exit(EXIT_FAILURE);
  }

  close(sockfd);


  return 0;
}
