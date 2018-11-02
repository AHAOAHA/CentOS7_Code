#include"../shared_mem.h"
int main()
{
  int shmid;
  char* shmp;
  shmid = CreatShm(1024);
  printf("%d\n", shmid);
  shmp = LinkShm(shmid);
  if(-1 == (int)shmp)
    exit(EXIT_FAILURE);
  while(30)
  {
    if(0 == strcmp(shmp, "quit\n"))
    {
      printf("quit Bye...\n");
      break;
    }
    printf("client# %s", shmp);
    fflush(stdout);
    sleep(1);

  }
 DestoryShm(shmid);

  return 0;
}
