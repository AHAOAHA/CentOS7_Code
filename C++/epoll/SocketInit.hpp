/*************************************************************************
*File Name: SocketInit.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Fri 22 Mar 2019 01:35:44 PM CST
 ************************************************************************/
#ifndef __SOCKET_INIT_HPP__
#define __SOCKET_INIT_HPP__

#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>
#include <arpa/inet.h>
#include <string.h>

using std::cerr;
using std::endl;

namespace AHAOAHA {
    int SetUpSocket(int16_t port, int listen_num) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock < 0) {
            cerr << "socket fail" << endl;
            return -1;
        }

        struct sockaddr_in saddr;
        bzero((void*)&saddr, sizeof(saddr));
        saddr.sin_family = AF_INET;
        saddr.sin_port = htons(port);
        saddr.sin_addr.s_addr = INADDR_ANY;

        int ret = bind(sock, (struct sockaddr*)&saddr, sizeof(saddr));
        if(ret < 0) {
            cerr << "bind fail" << endl;
            return -1;
        }

        ret = listen(sock, listen_num);
        if(ret < 0) {
            cerr << "listen fail" << endl;
            return -1;
        }

        return sock;
    }
}

#endif
