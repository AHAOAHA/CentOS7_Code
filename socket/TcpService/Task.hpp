/*************************************************************************
*File Name: Task.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月10日 星期四 10时15分02秒
 ************************************************************************/

#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef void (*Handler_t)(std::string& req, std::string& resp);
void Usage()
{
  std::cout << "./service [port]" << std::endl;
}

class Task
{
  public:
    Task(int fd, Handler_t handler):_client(fd), _handler(handler)
    {}

    void Run()
    {
      std::string req;
      std::string resp;
      char buf[1024];
      int ret = 0;
      while(1)
      {
        req.resize(0);
        resp.resize(0);
        memset(buf, '\0', sizeof(buf));
        ret = recv(_client, buf, sizeof(buf) - 1, 0);
        if(ret < 0)
        {
          std::cerr << "recv error" << std::endl;
          break;
        }
        if(ret == 0)
        {
          std::cerr << "client close" << std::endl;
          break;
        }

        req = buf;

        _handler(req, resp);

        ret = send(_client, resp.c_str(), resp.size(), 0);
        if(ret < 0)
        {
          std::cerr << "send fail" << std::endl;
          break;
        }

      }

      std::cout << "fd: " << _client << "is closed ..." << std::endl;
      close(_client);
    }

    int fd()
    {
      return _client;
    }

    ~Task()
    {
    }
  private:
    int _client;
    Handler_t _handler;
};
