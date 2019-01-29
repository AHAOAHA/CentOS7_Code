/*************************************************************************
*File Name: main.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月25日 星期五 09时03分04秒
 ************************************************************************/
#include "service.hpp"
#include <pthread.h>
#include "2048.h"


//保护传递的clientsock
pthread_mutex_t lock;

void* handler(void* arg)
{
  //分离线程并获得sockfd
  pthread_detach(pthread_self());
  int clientfd = *(int*)arg;
  pthread_mutex_unlock(&lock);


  //向客户端发送链接成功消息
  const char* buf = "connect success!\n";
  int ret = send(clientfd, buf, strlen(buf), 0);
  if(ret < 0)
  {
    std::cerr << "send fail!" << std::endl;
    goto end;
  }

  std::cout << clientfd << std::endl;
end:
  close(clientfd);
  return nullptr;
}



int main()
{
  static int clientfd = -1;

  pthread_mutex_init(&lock, nullptr);

  Sock service;
  service.SockInit(8080);
  struct sockaddr_in caddr;
  bzero((struct sockaddr*)&caddr, sizeof(caddr));
  socklen_t len = sizeof(caddr);

  //服务启动
  while(1)
  {
    clientfd = service.Accept((struct sockaddr*)&caddr, &len);
    pthread_t id;
    pthread_mutex_lock(&lock);
    pthread_create(&id, nullptr, handler, (void*)&clientfd);
  }
    
  return 0;
}
