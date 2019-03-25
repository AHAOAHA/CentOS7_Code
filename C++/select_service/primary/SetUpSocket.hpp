/*************************************************************************
 * File Name: SetUpSocket.hpp
 * Author: AHAOAHA
 * mail: ahaoaha_@outlook.com
 * Created Time: Mon 25 Mar 2019 07:59:59 PM CST
 ************************************************************************/
#ifndef __SETUP_SOCKET__
#define __SETUP_SOCKET__

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <iostream>
#include <string.h>

using std::cout;
using std::cerr;
using std::endl;

namespace AHAOAHA {
    int SetUpSocket(uint16_t port, int ltn = 5) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock < 0) {
            cerr << "socket fail" << endl;
            return -1;
        }
        int opt = 1;
        if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
            cerr << "setsockopt fail" << endl;
            return -2;
        }

        struct sockaddr_in saddr;
        memset(&saddr, 0, sizeof(saddr));
        saddr.sin_family = AF_INET;
        saddr.sin_port = htons(port);
        saddr.sin_addr.s_addr = INADDR_ANY;

        if(bind(sock, (struct sockaddr*)&saddr, sizeof(saddr)) < 0) {
            cerr << "bind fail" << endl;
            return -3;
        }

        if(listen(sock, ltn) < 0) {
            cerr << "listen fail" << endl;
            return -4;
        }
        return sock;
    }
}

#endif
