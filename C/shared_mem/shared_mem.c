#include"shared_mem.h"

int CreatShm(size_t size)
{
  return shmget(ftok(PATHNAME, PRO_ID), size, IPC_CREAT | IPC_EXCL);
}

int DestoryShm(int shmid)
{
  return shmctl(shmid, IPC_RMID, NULL);
}

void* LinkShm(int shmid)
{
  return shmat(shmid, NULL, SHM_RDONLY);
}
