/*************************************************************************
 * File Name: select.cc
 * Author: AHAOAHA
 * mail: ahaoaha_@outlook.com
 * Created Time: Mon 25 Mar 2019 07:55:09 PM CST
 ************************************************************************/
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include "SetUpSocket.hpp"
#include "Select.hpp"
#include <vector>

#define BUFSIZE 10240

int main(int argc, char *argv[]) {
    if(argc < 2) {
        return -1;
    }

    std::vector<int> fd_read;    //使用vector管理需要监听的套接字
    std::vector<int> fd_write;
    int max_sock = 0;
    fd_set readfds;
    fd_set writefds;


    //创建并初始化socket 并且使套接字处于listen状态
    int sock = AHAOAHA::SetUpSocket(atoi(argv[1]));
    AHAOAHA::AddFdToVec(fd_read, max_sock, sock);

    //将套接字添加进读文件描述符集合
    AHAOAHA::SetSet(fd_read, readfds);
    AHAOAHA::SetSet(fd_write, writefds);
    //开始监听
    for(;;) {
        int num = select(max_sock + 1, &readfds, &writefds, NULL, NULL);
        if(num < 0) {
            //fd_set清0 当readfds清0时 表示发生错误 TODO
            continue;
        }
        else if(num == 0) {
            //重新设置需要监听的文件描述符
            AHAOAHA::SetSet(fd_read, readfds);
            AHAOAHA::SetSet(fd_write, writefds);
            continue;
        }
        else {  //事件发生 处理事件
            for(size_t i = 0; i < fd_read.size(); ++i) { //判断读事件
                if(FD_ISSET(fd_read[i], &readfds)) {
                    //读事件发生
                    if(fd_read[i] == sock) { //套接字读事件
                        cout << "SOCKET CONNECT ..." << endl;
                        struct sockaddr_in caddr;
                        socklen_t len = sizeof(caddr);
                        int clientfd = accept(fd_read[i], (struct sockaddr*)&caddr, &len);
                        AHAOAHA::AddFdToVec(fd_read, max_sock, clientfd);
                        continue;
                    }
                    else { //读事件发生在客户端套接字
                        cout << "HTTP REQFD : " << i << endl;
                        cout << "HTTP REQUEST ..." << endl;
                        char buffer[BUFSIZE] = {0};
                        int ret = recv(fd_read[i], buffer, BUFSIZE - 1, 0);
                        if(ret == 0) { //对端关闭链接
                            close(fd_read[i]);
                            AHAOAHA::DelFdInVec(fd_read, max_sock, i);
                            //fd_read.erase(fd_read.begin()+i);
                            continue;
                        }
                        else if(ret < 0) { //发生错误
                            close(fd_read[i]);
                            AHAOAHA::DelFdInVec(fd_read, max_sock, i);
                            //fd_read.erase(fd_read.begin()+i);
                            continue;
                        }
                        else { //正常接收
                            buffer[ret] = 0;
                            cout << buffer << endl;
                            AHAOAHA::DelFdInVec(fd_read, max_sock, i);
                            //fd_read.erase(fd_read.begin()+i);
                            AHAOAHA::AddFdToVec(fd_write, max_sock, fd_read[i]);
                            //fd_write.push_back(fd_read[i]);
                            continue;
                        }
                    }
                } //读事件处理完毕
            }

            AHAOAHA::SetSet(fd_read, readfds); //重新设置读位图


            for(size_t i = 0; i < fd_write.size(); ++i) { //判断写事件
                if(FD_ISSET(fd_write[i], &writefds)) {
                    //写事件发生
                    std::string resp = "HTTP/1.1 200 OK\r\n\r\n<html><body><h1>hello select!</h1></body></html>\r\n";
                    write(fd_write[i], resp.c_str(), resp.size());  //无论写入正常与否 都是要关闭连接的
                    close(fd_write[i]);
                    AHAOAHA::DelFdInVec(fd_write, max_sock, i);
                }
            }
            AHAOAHA::SetSet(fd_write, writefds);
        }
    }
    for(auto e : fd_read) {
        close(e);
    }
    for(auto e : fd_write) {
        close(e);
    }
    return 0;
}
