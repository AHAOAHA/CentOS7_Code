/*
 * 注意：1.接受消息时，如果消息队列里没有符合要求的消息，则会发生堵塞，直至消息队列中出现符和要求的消息后并读取它
 */
#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>

#define PATHNAME "."
#define PRO_ID 0x6666

/*
 * type定义的值必须大于0
 */
#define SERVICE_TYPE 1
#define CLIENT_TYPE 2

struct msg_buf
{
  long type;
  char date[1024];
};

int CreatMsg();//创建消息队列，成功返回消息队列msgid,失败返回-1
int DestoryMsg(const int msgid);//删除消息队列，成功返回0，失败返回-1
int OpenMsg();//打开消息队列，打开成功返回消息队列msgid,失败返回-1
int SendMsg(int msgid,long who ,char* msg);//向消息队列发消息
int RecMsg(int msgid, long who,char msg[]);//从消息队列接受消息，成功返回0，并将消息写入msg，失败返回-1
#endif
