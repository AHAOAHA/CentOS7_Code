/*************************************************************************
*File Name: main.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月25日 星期五 09时03分04秒
 ************************************************************************/
#include "service.hpp"
#include <pthread.h>
#include "2048.h"
#include "game.h"

int array[ROW][COL] = {0};

int Flag_Seed = 1;
void* handle(void* arg)
{
  pthread_detach(pthread_self());
  Task* pt = (Task*)arg;
  std::cout << "get a clientfd "<< pt->GetClientfd() << std::endl;
  
  //todo游戏主体
  SuccessConnect(pt);

  Game(array, pt);

  delete pt;
  return nullptr;
}

void Usage()
{
  std::cout << "./service [port]" << std::endl;
}

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    Usage();
    exit(EXIT_FAILURE);
  }



  Sock service;
  service.SockInit(atoi(argv[1]));
  std::cout << "service running ..." << std::endl;

  //服务启动
  service.Run(handle);
    
  return 0;
}
