#include"../shared_mem.h"
int main()
{
  int shmid;
  char* shmp;
  shmid = GetShm(1024);
  shmp = LinkShm(shmid);
  printf("%x\n", shmp);
  if(-1 == (int)shmp)
    exit(EXIT_FAILURE);
  while(1)
  {
    printf("client: ");
    fflush(stdout);
    fgets(shmp, 1024, stdin);
    if(0 == strcmp(shmp, "quit\n"))
    {
      printf("Bye...\n");
      break;
    }
    sleep(1);
  }
  CutShm(shmp);
  return 0;
}
