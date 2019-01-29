/*************************************************************************
*File Name: main.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月29日 星期二 21时18分35秒
 ************************************************************************/
#include "client.hpp"

void Usage()
{
  std::cout << "./client [ip] [port]" << std::endl;
}

int main(int argc, char* argv[])
{
  if(argc < 3)
  {
    Usage();
    exit(EXIT_FAILURE);
  }
  Sock client;
  struct sockaddr_in saddr;
  bzero((struct sockaddr*)&saddr, sizeof(saddr));
  saddr.sin_family = AF_INET;
  saddr.sin_port = htons(atoi(argv[2]));
  saddr.sin_addr.s_addr = inet_addr(argv[1]);

  client.Connect((struct sockaddr*)&saddr);

  return 0;
}
