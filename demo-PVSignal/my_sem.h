/*
 * 封装二元信号量集
 */
#ifndef _MY_SEM_H_
#define _MY_SEM_H_

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<stdlib.h>
#include<wait.h>


//为ftok函数定义
#define PATHNAME "."
#define PRO_ID 0x6666

union semnu
{
  int val;
  struct semid_ds * buf;
  unsigned short *array;
  struct seminfo *_buf;
};

int CreatSem(int nums);
int CommSem(int nums, int semflg);
int InitSem(int semid, int nums, int initval);
int GetSem(int nums);
int DestorySem(int semid);
int PVcomm(int semid, int who, int op);
int P(int semid);
int V(int semid);
#endif
