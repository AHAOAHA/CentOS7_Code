#include<stdio.h>
#include<string.h>
#define MAX_CMD 1024
#define MAX_ARGV 20
int main()
{
  int i=0;
  int j=0;
  char* my_argv[MAX_ARGV] = {NULL}; 
  char cmd[MAX_CMD];
  char buf[]=" ";
  printf("[ahao@AHAOAHA bash]&");
  fgets()  
  my_argv[i] = strtok(cmd,buf);
  while(my_argv[i])
  {
    my_argv[++i] = strtok(NULL,buf);
  }

  for(j=0;j<=i;j++)
  {
    printf("%s\n",my_argv[j]);
  }
  return 0;
}
