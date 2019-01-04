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
#include<netinet/in.h>
#include<pthread.h>


char buf[1024];
char sendbuf[1024];
void* recFunc(void *arg)
{
  int clientfd = *(int*)arg;
  int recvret;
  while(1)
  {
    memset(buf, '\0', sizeof(buf));
    recvret = recv(clientfd, buf, sizeof(buf) - 1, 0);
    if(recvret == -1)
    {
      perror("recv error ... \n");
      exit(EXIT_FAILURE);
    }
    if(recvret == 0)
    {
      printf("client is down\n");
      pthread_exit(NULL);
    }

    printf("client: %s", buf);
  }

  return NULL;
}

int main()
{
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
  s_add.sin_addr.s_addr = inet_addr("0.0.0.0");

  s_add.sin_port = htons(8000);

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
    while(1)
    {
      pthread_t recthread;
      pthread_create(&recthread, NULL, recFunc, &accept_ret);
      pthread_detach(recthread);


      //向客户端发送消息
      
    }
  }
    
    
  return 0;
}
