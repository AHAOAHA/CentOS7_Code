/*************************************************************************
*File Name: UdpService.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月05日 星期六 13时05分00秒
 ************************************************************************/
#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <unistd.h>

class Sock
{
  public:
    typedef void (*Translate)(std::string& req, std::string& resp);

    Sock(char* ip, int port):_sock(-1), _ip(ip), _port(port)
    {}
  private:
    //初始化服务器
    void InitService()
    {
      int ret;
      //创建套接字
      _sock = socket(AF_INET, SOCK_DGRAM, 0);
      if(_sock < 0)
      {
        std::cerr << "socket fail" << std::endl;
        exit(EXIT_FAILURE);
      }
      struct sockaddr_in saddr;
      bzero(&saddr, sizeof(saddr));
      saddr.sin_family = AF_INET;
      saddr.sin_port = htons(_port);
      saddr.sin_addr.s_addr = inet_addr(_ip);
  
      //将套接字与服务器本地绑定
      ret = bind(_sock, (struct sockaddr*)&saddr, sizeof(saddr));
      if(ret < 0)
      {
        std::cerr << "bind error" << std::endl;
        exit(EXIT_FAILURE);
      }
    }

  public:
    void ServiceStart(Translate Handler)
    {
      int ret;
      char buf[1024];
      struct sockaddr_in caddr;
      socklen_t len = sizeof(caddr);
      InitService();
      std::string req;
      std::string resp;

      //进入事件循环
      for(;;)
      {
        req.resize(0);
        resp.resize(0);
        bzero(&caddr, sizeof(caddr));
        memset(buf, '\0', sizeof(buf));
        ret = recvfrom(_sock, buf, sizeof(buf) - 1, 0, (struct sockaddr*)&caddr, &len);
        if(ret < 0)
        {
          std::cerr << "recvfrom fail" << std::endl;
          continue;
        }

        req = buf;
        Handler(req, resp);

        sendto(_sock, resp.c_str(), resp.size(), 0, (struct sockaddr*)&caddr, sizeof(caddr));
      }


      close(_sock);
    }
  
    //服务器长期运行，所以析构函数并不必要做什么事情
    ~Sock()
    {}
  
  private:
    int _sock;
    char* _ip;
    int _port;
};



