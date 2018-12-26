/*************************************************************************
*File Name: service.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Tue 25 Dec 2018 02:50:32 PM CST
*************************************************************************/
#include "service.h"
#include "http.h"

void* ClientRequest(void* arg)
{
  int clsockfd = *(int*)arg;
  return (void*)handle(clsockfd);//调用请求处理方法
}

int setUp()
{
  //创建套接字
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(-1 == sockfd)
  {
    perror("socket fail ...\n");
    exit(EXIT_FAILURE);
  }
  
  int opt = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  //设置本地sockaddr结构体
  struct sockaddr_in local;
  local.sin_family = AF_INET;
  local.sin_port = htons(8080);
  local.sin_addr.s_addr = inet_addr("0.0.0.0");

  //将套接字和local绑定
  int bindRet = bind(sockfd, (struct sockaddr*)&local, sizeof(local));
  if(bindRet < 0)
  {
    perror("bind fail ...\n");
    exit(EXIT_FAILURE);
  }

  //开始监听
  
  int listenRet = listen(sockfd, 5);
  if(listenRet < 0)
  {
    perror("listen fail ...\n");
    exit(EXIT_FAILURE);
  }

  return sockfd;
}



int main()
{
  //服务器初始化
  int sockfd = setUp();

  printf("service running ...\n");
  //处理请求
  while(1)
  {
    struct sockaddr_in client;//保存客户端的sockaddr结构体
    socklen_t len = sizeof(client);

    int clsockfd = accept(sockfd, (struct sockaddr*)&client, &len);
    
    if(clsockfd < 0)
    {
      perror("accept fail ...\n");
      continue;
    }

    //创建线程处理请求
    pthread_t id;
    pthread_create(&id, NULL, ClientRequest, (void*)&clsockfd);
    pthread_detach(id);//分离线程
  }


  return 0;
}
