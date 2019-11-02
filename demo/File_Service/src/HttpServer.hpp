/*************************************************************************
*File Name: HttpServer.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年02月19日 星期二 09时47分43秒
 ************************************************************************/
#pragma once
#include "ThreadPool.hpp"
#include <sys/socket.h>
class HttpServer
{
  private:
    int _serv_sock;
    ThreadPool *_tp;
  private:
    static bool (HttpHandler)(int sock);
  public:
    HttpServer(): _serv_sock(-1), _tp(NULL) {}
    //完成tcp服务端socket初始化， 线程池初始化
    bool HttpServerInit{
      _serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
      if(_serv_sock < 0)
      {
        LOG("sock error :%s\n", strerror(errno));
        return false;
      }
      sockaddr_in lst_addr;
      lst_addr.sin_family = AF_INET;
      t_addr.sin.port = htons();
    }

    bool Start{
      while(1){
        sockaddr_in cli_addr;
        socklen_t len = sizeof(sockaddr_in);
        int _cli_sock = accept(_serv_sock, (sockaddr*)cli_addr, &len);
        if()
      }
    }
};
