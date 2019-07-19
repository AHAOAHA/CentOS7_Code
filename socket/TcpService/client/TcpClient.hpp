/*************************************************************************
*File Name: UdpClient.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月05日 星期六 14时57分18秒
 ************************************************************************/
#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

void Usage()
{
  std::cout << "./client [ip] [port]" << std::endl;
}

class Sock
{
  public:
    Sock(char* ip, int16_t port):_sock(-1), _ip(ip), _port(port)
    {}

    void InitSock()
    {
      int ret;
      _sock = socket(AF_INET, SOCK_STREAM, 0);
      if(_sock < 0)
      {
        std::cerr << "socket fail" << std::endl;
        exit(EXIT_FAILURE);
      }
      bzero(&saddr, sizeof(saddr));
      saddr.sin_family = AF_INET;
      saddr.sin_port = htons(_port);
      saddr.sin_addr.s_addr = inet_addr(_ip);

      ret = connect(_sock, (struct sockaddr*)&saddr, sizeof(saddr));
      if(ret < 0)
      {
        std::cerr << "connect fail" << std::endl;
        exit(EXIT_FAILURE);
      }
      std::cout << "connect ret " << ret << std::endl;
    }
    ~Sock()
    {
      close(_sock);
    }
    ssize_t Send(std::string& req)
    {
      return send(_sock, req.c_str(), req.size(), 0);
    
    }

    ssize_t Recv(char* buf, size_t size)
    {
      return recv(_sock, buf, size, 0);
    }


  private:
    int _sock;
    char* _ip;
    int16_t _port;
    struct sockaddr_in saddr;
};
