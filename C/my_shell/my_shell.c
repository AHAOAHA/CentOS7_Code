#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#define MAX_ARGV 20
#define MAX_CMD 1024

int cmd_cut(char cmd[], char* argv[])//发生重定向则返回重定向符号所在位置
{
  char* buf = " ";
  int i = 0;
  int stdout_off = 0;
  char stdout_file_name[50];
  argv[i++] = strtok(cmd, buf);
  while(argv[i++]=strtok(NULL, buf))
  {
    if(*argv[i-1]=='>'||
       *argv[i-1]=='<'||
       *argv[i-1]=='&')
    {
      //记录重定向符号位置
      stdout_off = i - 1;
    }
  }

  //处理末尾输入的'\n'
  argv[i - 1] = NULL;
  if(*argv[i - 2] == '\n')
  {
    argv[i - 2] = NULL;
  }
  else
  {
    char* p = (argv[i-2] + strlen(argv[i-2]) - 1);
    *p = '\0';
  }

  //判断是否发生重定向
  if(stdout_off != 0)
  {
    return stdout_off;
  }
  return 0;
}

int which_redirect(char* argv[], const int redirect)
{
  char stdout_file_name[50];
  if(redirect != 0)
  {
    strcpy(stdout_file_name, argv[redirect+1]);//保存输出/输入文件名
    if(*argv[redirect] == '>')//输出重定向
    {
      argv[redirect] = NULL;
      close(1);
      return open(stdout_file_name, O_WRONLY|O_CREAT);
    }
    else if(*argv[redirect] == '<')//输入重定向
    {
      argv[redirect] = NULL;
      close(0);
      return open(stdout_file_name, O_WRONLY|O_CREAT);
    }
    else if(*argv[redirect] == '&')
    {
      argv[redirect] = NULL;
      close(1);
    }
    else
    {
      printf("重定向标识符错误!\n");
      exit(0);
    }
  }

  return -1;
}

void new_pro(char* argv[], const int redirect)
{
  pid_t id=fork();
  char stdout_file_name[20];
  int fd = -1;
  if(-1==id)
  {
    perror("fork");
    exit(-1);
  }
  else if(0==id)//子进程
  {
    fd = which_redirect(argv,redirect);//判断输出/输入/不发生重定向 并处理 
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
  int redirect = 0;//重定向标识符 默认不发生重定向
  while(1)
  {
    printf("[ahao@AHAOAHA ~ ]& ");
    fgets(cmd,sizeof(cmd),stdin);
    redirect = cmd_cut(cmd,argv);
    new_pro(argv, redirect);
  }
  close(1);
  return 0;
}
