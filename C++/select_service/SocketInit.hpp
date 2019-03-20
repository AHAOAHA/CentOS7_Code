/*************************************************************************
*File Name: SocketInit.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Tue 19 Mar 2019 02:57:40 PM CST
 ************************************************************************/
#ifndef __SOCKET_INIT__
#define __SOCKET_INIT__
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <iostream>
#include <string.h>
using std::endl;
using std::cerr;
using std::cout;

class Sock
{
  private:
    int _sock;
  public:
    Sock():_sock(-1)
    {}

    bool Setup(int16_t port, int listen_num) {
      struct sockaddr_in saddr;
      bzero(&saddr, sizeof(saddr));
      saddr.sin_family = AF_INET;
      saddr.sin_port = htons(port);
      saddr.sin_addr.s_addr = INADDR_ANY;
      _sock = socket(AF_INET, SOCK_STREAM, 0);
      if(_sock < 0) {
        cerr << "socket fail" << endl;
        return false;
      }

      int opt = 1;
      int ret = setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
      if(ret < 0) {
        return false;
      }

      if(bind(_sock, (struct sockaddr*)&saddr, sizeof(struct sockaddr)) < 0) {
        cerr << "bind fail" << endl;
        return false;
      }
      
      if(listen(_sock, listen_num) < 0) {
        cerr << "listen fail" << endl;
        return false;
      }
      return true;
    }

    int GetSock()const {
      return _sock;
    }
}; 

#endif
