/*************************************************************************
*File Name: service.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月25日 星期五 09时04分12秒
 ************************************************************************/
#pragma once
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>

class Sock
{
  public:
    Sock():_sock(-1)
    {}
    
    void SockInit(uint16_t port)
    {
      _sock = socket(AF_INET, SOCK_STREAM, 0);
      if(_sock  < 0)
      {
        std::cerr << "socket fail!" << std::endl; 
        exit(EXIT_FAILURE);
      }

      bzero(&saddr, sizeof(saddr));
      saddr.sin_family = AF_INET;
      saddr.sin_port = htons(port);
      saddr.sin_addr.s_addr = INADDR_ANY;

      int ret = bind(_sock, (struct sockaddr*)&saddr, sizeof(saddr));
      if(ret < 0)
      {
        std::cerr << "bind fail!" << std::endl;
        exit(EXIT_FAILURE);
      }
      
      ret = listen(_sock, 5);
      if(ret < 0)
      {
        std::cerr << "listen fail!" << std::endl;
        exit(EXIT_FAILURE);
      }
    }

    int Accept()
    {
      socklen_t len = sizeof(saddr);
      int ret = accept(_sock, (struct sockaddr*)&saddr, &len);
      if(ret < 0)
      {
        std::cerr << "accept fail!" << std::endl;
      }
      return ret;
    }

    ~Sock()
    {}
  private:
    int _sock;
    struct sockaddr_in saddr;
};
