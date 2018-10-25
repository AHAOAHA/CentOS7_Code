#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
  
  char buf[64];
  FILE* f = fopen("file", "r");
  fgets(buf, 64, f);

  printf("%s",buf);
  fclose(f);
  return 0;
}
