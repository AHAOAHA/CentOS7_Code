/*************************************************************************
*File Name: main.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月25日 星期五 09时03分04秒
 ************************************************************************/
#include "service.hpp"
#include <pthread.h>
#include "2048.h"



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
  service.Run();
    
  return 0;
}
