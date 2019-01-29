/*************************************************************************
*File Name: client.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月29日 星期二 21时15分28秒
 ************************************************************************/
#pragma once
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>

class Sock
{
  public:
    Sock():_sock(-1)
    {}

    void Connect(struct sockaddr* saddr)
    {
      _sock = socket(AF_INET, SOCK_STREAM, 0);
      if(_sock < 0)
      {
        std::cerr << "socket fail!" << std::endl;
        exit(EXIT_FAILURE);
      }

      int ret = connect(_sock, saddr, sizeof(saddr));
      if(ret < 0)
      {
        std::cerr << "connect fail!" << std::endl;
        exit(EXIT_FAILURE);
      }
    }

    ~Sock()
    {
      close(_sock);
    }
  private:
    int _sock;
};
