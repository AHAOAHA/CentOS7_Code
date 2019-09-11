#include"./my_sem.h"

int CommSem(int nums, int semflg)
{
  key_t key = ftok(PATHNAME, PRO_ID);
  if(key < 0)
  {
    exit(EXIT_FAILURE);
  }

  return semget(key, nums, semflg);
}

//创建信号量集
int CreatSem(int nums)
{
  return CommSem(nums, IPC_CREAT|IPC_EXCL|0644);
}

//得到已创建的信号量集
int GetSem(int nums)
{
  return CommSem(nums, IPC_CREAT);
}


int PVcomm(int semid, int who, int op)
{
  struct sembuf _sembuf;
  _sembuf.sem_num = who;
  _sembuf.sem_op = op;
  _sembuf.sem_flg = 0;

  return semop(semid, &_sembuf, 1);
}

//对信号量集进行P操作，该处即为给信号量的计数值-1
int P(int semid)
{
  return PVcomm(semid, 0, -1);
}

//对信号量进行V操作，该处即为给信号量的计数值+1
int V(int semid)
{
  return PVcomm(semid, 0, +1);
}

//删除信号量集
int DestorySem(int semid)
{
  return semctl(semid, 0, IPC_RMID);
}


//初始化信号量集，二元信号量集初始信号量计数值应该初始化为1
int InitSem(int semid, int nums, int initval)
{
  union semnu _semnu;
  _semnu.val = initval;
  return semctl(semid, nums, SETVAL, _semnu);
}
