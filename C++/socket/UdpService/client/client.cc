/*************************************************************************
*File Name: client.cc
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月05日 星期六 14时53分04秒
 ************************************************************************/
#include "UdpClient.hpp"

int main(int argc, char* argv[])
{
  if(argc < 3)
  {
    Usage();
    exit(EXIT_FAILURE);
  }
  Sock sock(argv[1], atoi(argv[2]));


  char buf[1024];
  std::string req;
  int ret;
  while(1)
  {
    req.reserve(0);
    std::cout << "client: ";
    std::cin >> req;
    ret = sock.SendTo(req);
    if(ret < 0)
    {
      std::cerr << "sendto fail" << std::endl;
      continue;
    }
    memset(buf, '\0', sizeof(buf));
    ret = sock.RecvFrom(buf, sizeof(buf));
    if(ret < 0)
    {
      std::cerr << "recvfrom fail" << std::endl;
      continue;
    }

    std::cout << "service echo:"<< buf << std::endl;
    
  }
  
  return 0;
}
