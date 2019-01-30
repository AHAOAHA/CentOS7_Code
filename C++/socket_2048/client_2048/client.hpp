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
#include "../service_2048/2048.h"

class CSock
{
  public:
    CSock():_sock(-1)
    {}

    int Connect(char* ip, uint16_t port)
    {
      _sock = socket(AF_INET, SOCK_STREAM, 0);
      if(_sock < 0)
      {
        std::cerr << "socket fail!" << std::endl;
        exit(EXIT_FAILURE);
      }
    bzero((struct sockaddr*)&_saddr, sizeof(_saddr));
    _saddr.sin_family = AF_INET;
    _saddr.sin_port = htons(port);
    _saddr.sin_addr.s_addr = inet_addr(ip);

      return connect(_sock, (struct sockaddr*)&_saddr, sizeof(_saddr));
    }

    ssize_t Recv(void* buf, size_t size)
    {
      return recv(_sock, buf, size, 0);
    }

    ssize_t Send(void* buf, size_t size)
    {
      return send(_sock, buf, size, 0);
    }




    ~CSock()
    {
      close(_sock);
    }
  private:
    int _sock;
    struct sockaddr_in _saddr;
};
