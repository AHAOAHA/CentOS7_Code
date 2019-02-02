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

typedef void* (*handle_t)(void*);

class Task
{
  public:
    Task(int clientfd):_clientfd(clientfd)
    {}
    ~Task()
    {
      close(_clientfd);
    }

    //发送信息
    ssize_t Send(void* buf, size_t size)
    {
      return send(_clientfd, buf, size, 0);
    }

    //接受消息
    ssize_t Recv(void* buf, size_t size)
    {
      return recv(_clientfd, buf, size, 0);
    }

    int GetClientfd()
    {
      return _clientfd;
    }

  private:
    int _clientfd;
};




class Sock
{
  public:
    Sock():_sock(-1)
    {}
    
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

    void Run(handle_t handle)
    {
      while(1)
      {
        struct sockaddr_in caddr;
        socklen_t len;
        int clientfd = accept(_sock, (struct sockaddr*)&caddr, &len);


        Task* pt = new Task(clientfd);
        pthread_t id;
        pthread_create(&id, nullptr, handle, (void*)pt);
      }
    }



    ~Sock()
    {}
  private:
    int _sock;
    struct sockaddr_in _saddr;
};
