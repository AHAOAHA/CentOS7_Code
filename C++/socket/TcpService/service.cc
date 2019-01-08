/*************************************************************************
*File Name: service.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月07日 星期一 10时40分13秒
 ************************************************************************/
#include "service.hpp"

//创建服务器

int main(int argc, char* argv[])
{
  if(argc < 3)
  {
    Usage();
    exit(EXIT_FAILURE);
  }
  Sock service;
  service.InitSock(argv[1], atoi(argv[2]));
  service.Run();
  return 0;
}
