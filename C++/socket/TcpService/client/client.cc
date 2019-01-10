/*************************************************************************
*File Name: client.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月05日 星期六 14时53分04秒
 ************************************************************************/
#include "TcpClient.hpp"

int main(int argc, char* argv[])
{
  if(argc < 3)
  {
    Usage();
    exit(EXIT_FAILURE);
  }
  Sock sock(argv[1], atoi(argv[2]));
  sock.InitSock();


  char buf[1024];
  std::string req;
  int ret;
  while(1)
  {
    req.resize(0);
    std::cout << "client<exit即退出>: ";
    std::cin >> req;
    if(strcmp("exit", req.c_str()) == 0)
    {
      break;
    }
    ret = sock.Send(req);
    if(ret < 0)
    {
      std::cerr << "send fail" << std::endl;
      continue;
    }
    memset(buf, '\0', sizeof(buf));
    ret = sock.Recv(buf, sizeof(buf));
    if(ret < 0)
    {
      std::cerr << "recv fail" << std::endl;
      continue;
    }

    std::cout << "service echo:"<< buf << std::endl;
    
  }
  
  
  return 0;
}
