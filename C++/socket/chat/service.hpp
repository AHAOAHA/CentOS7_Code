/*************************************************************************
*File Name: service.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Fri 28 Dec 2018 08:06:26 PM CST
 ************************************************************************/
#pragma once
#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>
#include <arpa/inet.h>
#include <strings.h>
#include <stdlib.h>

class SeverSock
{
  public:
    SeverSock(int port):_sock(-1), _port(port)
    {}

    void InitSock()
    {
      _sock = socket(AF_INET, SOCK_STREAM, 0);
      if(_sock < 0)
      {
        std::cerr << "InitSock fail" << std::endl;
        exit(EXIT_FAILURE);
      }

      struct sockaddr_in sever_addr;
      bzero(&sever_addr, sizeof(sever_addr));
      sever_addr.sin_family = AF_INET;
      sever_addr.sin_port = htons(_port);
      sever_addr.sin_addr.s_addr = INADDR_ANY;

      if(bind(_sock, (struct sockaddr*)&sever_addr, sizeof(sever_addr)) < 0)
      {
        std::cerr << "bind fail" << std::endl;
        exit(EXIT_FAILURE);
      }

      if(listen(_sock, 5) < 0)
      {
        std::cerr << "listen fail" << std::endl;
        exit(EXIT_FAILURE);
      }
    }

    int SockAccept(struct sockaddr* client_addr, socklen_t *len)
    {
      return accept(_sock, client_addr, len);
    }

    ~SeverSock()
    {
    }
  private:
    int _sock;
    int _port;
};

void Usage()
{
  std::cout << "./service [port]" << std::endl;
}
