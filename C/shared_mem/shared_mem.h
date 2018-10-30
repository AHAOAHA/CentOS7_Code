/*
 * 封装共享内存接口
 */



#ifndef _SHARED_MEM_H_
#define _SHARED_MEM_H_

#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<sys/types.h>

#define PATHNAME "."
#define PRO_ID 0x6666

int CreatShm(size_t size);
int DestoryShm(int shmid);

void* LinkShm(int shmid);

#endif
