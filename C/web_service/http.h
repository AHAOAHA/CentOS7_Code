/*************************************************************************
*File Name: http.h
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Tue Dec 25 23:18:38 2018
 ************************************************************************/
#pragma once
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <strings.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/sendfile.h>

#define SIZE 4096

int handle(int clsockfd);//主处理函数
int GetLine(int clsockfd, char *buf, int len);
int ClearHeader(int clsockfd);
int ShowWWW(int clsockfd, char *path, ssize_t size);
void ErrorRequest(const char *path, const char *head, int clsockfd);
void ShowError(int clsockfd, int error_code); 
