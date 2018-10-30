#include"../shared_mem.h"
int main()
{
  int shmid;
  shmid = CreatShm(1024);
  printf("%d\n", shmid);
  printf("%x\n", LinkShm(shmid));
  printf("%d\n", DestoryShm(shmid));

  return 0;
}
