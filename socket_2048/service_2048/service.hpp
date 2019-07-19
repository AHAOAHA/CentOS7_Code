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
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "2048.h"

#include "PthreadPool.hpp"
#include "Task.hpp"

typedef void* (*handle_t)(void*);

class Sock
{
  public:
    Sock():_sock(-1), _pl(1)
    {
      //初始化线程池
      _pl.PthreadInit();
    }
    
    void SockInit(uint16_t port)
    {
      int ret = 0;
      _sock = socket(AF_INET, SOCK_STREAM, 0);
      if(_sock  < 0)
      {
        std::cerr << "socket fail!" << std::endl; 
        exit(EXIT_FAILURE);
      }


      //设置服务器立即重启
      int opt = 1;
      ret = setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
      if(ret  < 0)
      {
        std::cerr << "setsockopt fail!" << std::endl;
        exit(EXIT_FAILURE);
      }

      bzero(&_saddr, sizeof(_saddr));
      _saddr.sin_family = AF_INET;
      _saddr.sin_port = htons(port);
      _saddr.sin_addr.s_addr = inet_addr("0.0.0.0");

      ret = bind(_sock, (struct sockaddr*)&_saddr, sizeof(_saddr));
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

    void Run()
    {
      int fd;
      while(1)
      {
        struct sockaddr_in caddr;
        socklen_t len;
        int clientfd = accept(_sock, (struct sockaddr*)&caddr, &len);
        
        umask(0);
        fd = open("log_ip.txt", O_CREAT|O_APPEND|O_WRONLY, 0644);


        std::string client_ip(inet_ntoa(((struct sockaddr_in)caddr).sin_addr));

        write(fd, client_ip.c_str(), client_ip.size());
        close(fd);


        Task t(clientfd);
        _pl.AddTask(t);
      }
    }



    ~Sock()
    {}
  private:
    int _sock;
    struct sockaddr_in _saddr;
    PthreadPool _pl;
};
