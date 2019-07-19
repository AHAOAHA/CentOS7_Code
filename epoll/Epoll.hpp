/*************************************************************************
*File Name: Epoll.hpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Fri 22 Mar 2019 01:49:03 PM CST
 ************************************************************************/
#ifndef __EPOLL_HPP__
#define __EPOLL_HPP__

#define EPOLLSIZE 10

#include <sys/epoll.h>
#include <iostream>

using std::cerr;
using std::endl;

namespace AHAOAHA {
    class Epoll {
        private:
            int _epfd;
        private:
            int CreateEpoll() {
                return epoll_create(EPOLLSIZE);
            }
        public:
            Epoll():_epfd(-1) 
            {}

            bool EpollInit() {
                _epfd = CreateEpoll();
                if(_epfd < 0) {
                    cerr << "create epoll fail" << endl;
                    return false;
                }
                return true;
            }

            bool EpollDelFd(int fd) {
                int ret = epoll_ctl(_epfd, EPOLL_CTL_DEL, fd, NULL);
                if(ret < 0) {
                    return false;
                }
                return true;
            }

            bool EpollAddFd(int fd, int ets) {
                struct epoll_event events;
                events.events = ets;
                events.data.fd = fd;
                int ret = epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &events);
                if(ret == -1) {
                    return false;
                }
                return true;
            }

            bool EpollChangeMod(int fd, int ets) {
                struct epoll_event events;
                events.events = ets;
                events.data.fd = fd;
                int ret = epoll_ctl(_epfd, EPOLL_CTL_MOD, fd, &events);
                if(ret < 0) {
                    return false;
                }
                return true;
            }

            int EpollWait(struct epoll_event* events, int maxsize, int timeout) {
                return epoll_wait(_epfd, events, maxsize, timeout);
            }
    };

}


#endif
