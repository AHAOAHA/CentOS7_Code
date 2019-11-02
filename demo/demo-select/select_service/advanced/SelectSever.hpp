/*************************************************************************
*File Name: SelectSever.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Tue 19 Mar 2019 02:38:14 PM CST
 ************************************************************************/
#ifndef __SELECT_SERVER__
#define __SELECT_SERVER__
#include "SocketInit.hpp"
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <unordered_map>
#include <vector>

class SelectSever
{
  private:
    fd_set _read_fds; //记录select要监听的文件描述符
    int _max_fd;  //记录最大的文件描述符
    std::unordered_map<int, Sock> _map;
  public:
    SelectSever():_max_fd(0) {
      FD_ZERO(&_read_fds);  //进行初始化
    }

    bool AddFd(const Sock& sock) {
      int fd = sock.GetSock();
      cout << "< select[add]: " << fd << endl;
      if(_map.find(fd) != _map.end()) {
        //说明该文件描述符已经存在
        return false;
      }
      _map[fd] = sock;  //将该文件描述符添加进map
      FD_SET(fd, &_read_fds);
      if(fd > _max_fd) {
        _max_fd = fd;
      }
      return true;
    }

    bool DelFd(const Sock& sock) {
      int fd = sock.GetSock();
      cout << "< select[del]: " << fd << endl;
      if(_map.find(fd) == _map.end()) {
        //当前select中没有要删除的socket
        return false;
      }
      _map.erase(fd);
      FD_CLR(fd, &_read_fds);

      //重新设置最大的文件描述符
      for(auto it = _map.begin(); it != _map.end(); ++it) {
        if(it->first > _max_fd) {
          _max_fd = it->first;
        }
      }
      return true;
    }

  //返回读文件就绪的文件描述符
    bool Wait(std::vector<Sock>& output) {
      output.clear();
      fd_set tmp = _read_fds;
      int nfds = select(_max_fd + 1, &tmp, NULL, NULL, NULL);
      if(nfds < 0) {
        //出现错误
        return false;
      }

      for(int i = 0; i < _max_fd + 1; ++i) {
        if(FD_ISSET(i, &tmp)) {
          output.push_back(_map[i]);
        }
        else
          continue;
      }
      return true;
    }
};

#endif
