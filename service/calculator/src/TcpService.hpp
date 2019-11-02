/*************************************************************************
*File Name: service.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月07日 星期一 10时40分04秒
 ************************************************************************/
#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "Task.hpp"
#include "PthreadPool.hpp"
//创建套接字类
class Sock
{
  public:
    Sock():_sock(-1), _pl(1)
    {
      _pl.PthreadPoolInit();
    }

    //初始化套接字：将套接字与ip及端口进行绑定
    void InitSock(int port)
    {
      int ret;
      _sock = socket(AF_INET, SOCK_STREAM, 0);
      if(_sock < 0)
      {
        std::cerr << "socket fail" << std::endl;
        exit(EXIT_FAILURE);
      }

      //设置服务器立即重启
      int opt = 1;
      ret = setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
      if(ret < 0)
      {
        std::cerr << "setsockopt fail" << std::endl;
        exit(EXIT_FAILURE);
      }

      struct sockaddr_in saddr;
      bzero(&saddr, sizeof(saddr));
      saddr.sin_family = AF_INET;
      saddr.sin_port = htons(port);
      saddr.sin_addr.s_addr = inet_addr("0.0.0.0");

      //绑定套接字与本地服务器
      re = bind(_sock, (struct sockaddr*)&saddr, sizeof(saddr));
      if(ret < 0)
      {
        std::cerr << "bind fail" << std::endl;
        exit(EXIT_FAILURE);
      }

      //设置监听状态
      ret = listen(_sock, 5);
      if(ret < 0)
      {
        std::cerr << "listen fail" << std::endl;
        exit(EXIT_FAILURE);
      }
    }

    void Run(Handler_t handler)
    {
      int client;
      struct sockaddr_in caddr;
      socklen_t len = sizeof(caddr);
      bzero(&caddr, sizeof(caddr));

      for(;;)
      {
        client = accept(_sock, (struct sockaddr*)&caddr, &len);
        if(client < 0)
        {
          std::cerr << "accept fail" << std::endl;
          continue;
        }
        Task t(client, handler);
        _pl.AddTask(t);
      }
    }

    ~Sock()
    {}
  private:
    int _sock;
    PthreadPool _pl;
};
