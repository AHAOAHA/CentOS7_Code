/*************************************************************************
 *File Name: epoll.cc
 *Author: AHAOAHA
 *mail: ahaoaha_@outlook.com
 *Created Time: Fri 22 Mar 2019 01:32:44 PM CST
 ************************************************************************/
#include "SocketInit.hpp"
#include "Epoll.hpp"
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

#define BUFSIZE 10240

int main(int argc, char* argv[]) {
    if(argc < 2) {
        return -1;
    }
    int sock = AHAOAHA::SetUpSocket(atoi(argv[1]), 5);
    AHAOAHA::Epoll epoll;
    epoll.EpollInit();
    epoll.EpollAddFd(sock, EPOLLIN);

    struct epoll_event events[EPOLLSIZE];
    for(;;) {
        int size = epoll.EpollWait(events, EPOLLSIZE, 5000);
        if(size > 0) {
            for(size_t i = 0; i < static_cast<size_t>(size); ++i) {
                if(events[i].data.fd == sock) {
                    //有新连接申请建立连接
                    struct sockaddr_in peer;
                    bzero((void*)&peer, sizeof(peer));
                    socklen_t len = sizeof(peer);
                    int clifd = accept(sock, (struct sockaddr*)&peer, &len);
                    if(clifd < 0) {
                        //建立新连接错误
                        continue;
                    }
                    else {
                        epoll.EpollAddFd(clifd, EPOLLIN);
                    }
                }
                else {
                    if(events[i].events == EPOLLIN) {
                        //I/O事件为HTTP请求
                        char buf[BUFSIZE] = {0};
                        ssize_t ret = recv(events[i].data.fd, buf, BUFSIZE - 1, 0);
                        if(ret <= 0) {
                            //对端关闭连接
                            close(events[i].data.fd);
                            epoll.EpollDelFd(events[i].data.fd);
                            continue;
                        }
                        else {
                            //接收正确
                            buf[ret] = 0;
                            cout << buf << endl;
                            epoll.EpollChangeMod(events[i].data.fd, EPOLLOUT);
                        }
                    }
                    else if(events[i].events == EPOLLOUT) {
                        //就绪的为HTTP请求的写事件
                        std::string resp;
                        resp = "HTTP/1.1 200 OK\r\n\r\n<html><body><h2>hello epoll server!</h2></body></html>";
                        int send_ret = send(events[i].data.fd, resp.c_str(), resp.size(), 0);
                        if(send_ret < 0) {
                            //写入失败
                            //TODO
                            close(events[i].data.fd);
                            epoll.EpollDelFd(events[i].data.fd);
                        }
                        else {
                            close(events[i].data.fd);
                            epoll.EpollDelFd(events[i].data.fd);
                        }
                    }
                }
            }
        }
        else {
            cout << "< time out ..." << endl;
        }

    }


    return 0;
}
