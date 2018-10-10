#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
#define MAX_ARGV 20
#define MAX_CMD 1024
void cut_str(char* argv[],char cmd[])
{
  char* ptr=cmd;
  int i=0;
  int flag=0;
  while(*ptr!='\0')
  {
    if(*ptr!=' '&&flag==0)
    {
      argv[i++]=ptr;
      flag=1;
    }
    else if(*ptr==' '&&flag==1)
    {
      *ptr='\0'; 
      argv[i++]=ptr+1;
    }
    ptr+=1;
  }
  ptr=argv[i-1];
  while(*ptr!='\0')
  {
    ptr+=1;
  }
  *(ptr-1)='\0';
  argv[i]=NULL;
}

void new_pro(char* argv[])
{
  pid_t id=fork();
  if(-1==id)
  {
    perror("fork");
    exit(-1);
  }
  else if(0==id)//子进程
  {
    execvp(argv[0],argv);
  }
  else//父进程
  {
    int st;
    while(wait(&st)!=id);
  }
}
int main()
{
  char cmd[MAX_CMD]={'\0'};
  char* argv[MAX_ARGV];
  while(1)
  {
    printf("[ahao@AHAOAHA ~ ]& ");
    fgets(cmd,sizeof(cmd),stdin); 
    cut_str(argv,cmd);
    new_pro(argv);
  }
  return 0;
}
