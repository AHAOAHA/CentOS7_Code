/*
 * 封装共享内存接口
 */



#ifndef _SHARED_MEM_H_
#define _SHARED_MEM_H_

#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

#define PATHNAME "."
#define PRO_ID 0x6666

int CreatShm(size_t size);
int DestoryShm(int shmid);
int GetShm(int size);
void* LinkShm(int shmid);


#endif
