/*************************************************************************
*File Name: main.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Fri 28 Dec 2018 08:06:08 PM CST
 ************************************************************************/
#include "service.hpp"

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    Usage();
    exit(EXIT_FAILURE);
  }

  //启动服务
  SeverSock seversock(atoi(argv[1]));
  seversock.InitSock();
  
  struct sockaddr_in client_addr;
  bzero(&client_addr, sizeof(client_addr));
  socklen_t len;

  while(1)
  {
    seversock.SockAccept((struct sockaddr*)&client_addr, &len);
  }
  return 0;
}
