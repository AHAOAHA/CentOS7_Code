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
      _sock = socket(AF_INET, SOCK_DGRAM, 0);
      if(_sock < 0)
      {
        std::cerr << "socket fail" << std::endl;
        exit(EXIT_FAILURE);
      }
    }
    ~Sock()
    {
      close(_sock);
    }
    ssize_t SendTo(std::string& req)
    {
      struct sockaddr_in saddr;
      bzero(&saddr, sizeof(saddr));
      saddr.sin_family = AF_INET;
      saddr.sin_port = htons(_port);
      saddr.sin_addr.s_addr = inet_addr(_ip);
      return sendto(_sock, req.c_str(), req.size(), 0, (struct sockaddr*)&saddr, sizeof(saddr));
    
    }

    ssize_t RecvFrom(char* buf, size_t size)
    {
      struct sockaddr_in caddr;
      socklen_t len;
      return recvfrom(_sock, buf, size, 0, (struct sockaddr*)&caddr, &len);
    }


  private:
    int _sock;
    char* _ip;
    int16_t _port;
};
