#include"shared_mem.h"

int CreatShm(size_t size)
{
  umask(0);
  return shmget(ftok(PATHNAME, PRO_ID), size, IPC_CREAT | IPC_EXCL | 0644);
}

int DestoryShm(int shmid)
{
  return shmctl(shmid, IPC_RMID, NULL);
}

int GetShm(int size)
{
  return shmget(ftok(PATHNAME, PRO_ID), size, IPC_CREAT);
}
void* LinkShm(int shmid)
{
  return shmat(shmid, NULL, 0);
}
