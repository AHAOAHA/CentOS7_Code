/*************************************************************************
*File Name: service.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Tue 25 Dec 2018 02:50:32 PM CST
*************************************************************************/
#include "service.h"
#include "http.h"


//记录log信息
void PrintLog(const char* logstr)
{
  char log[1024];
  strcpy(log, GetTime());
  strcat(log, logstr);
  perror(log);
}


//设置记录时间的结构体
char* GetTime()
{
  struct tm *ptm = NULL;
  char *ptime;
  time_t t;
  time(&t);

  ptm = localtime(&t);

  ptime = asctime(ptm);

  return ptime;
}

int handle_ret;
void* ClientRequest(void* arg)
{
  int clsockfd = *(int*)arg;
  handle_ret = handle(clsockfd);//调用请求处理方法
  return (void*)&handle_ret;
}

int setUp()
{

  //关闭标准错误文件描述符，将所有的错误信息打印至log文件中
  close(2);
  open("log", O_CREAT | O_WRONLY | O_APPEND, 0777);
  //创建套接字
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(-1 == sockfd)
  {
    PrintLog("socket fail");
    exit(EXIT_FAILURE);
  }
  
  int opt = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  //设置本地sockaddr结构体
  struct sockaddr_in local;
  local.sin_family = AF_INET;
  local.sin_port = htons(8080);
  local.sin_addr.s_addr = inet_addr("0.0.0.0");

  //将套接字和local绑定
  int bindRet = bind(sockfd, (struct sockaddr*)&local, sizeof(local));
  if(bindRet < 0)
  {
    PrintLog("bind fail");
    exit(EXIT_FAILURE);
  }

  //开始监听
  
  int listenRet = listen(sockfd, 5);
  if(listenRet < 0)
  {
    PrintLog("listen fail");
    exit(EXIT_FAILURE);
  }

  return sockfd;
}



int main()
{
  //服务器初始化
  int sockfd = setUp();

  printf("%s service running ...\n", GetTime());
  //处理请求
  while(1)
  {
    struct sockaddr_in client;//保存客户端的sockaddr结构体
    socklen_t len = sizeof(client);

    int clsockfd = accept(sockfd, (struct sockaddr*)&client, &len);
    
    if(clsockfd < 0)
    {
      PrintLog("accept fail");
      continue;
    }

    //创建线程处理请求
    pthread_t id;
    pthread_create(&id, NULL, ClientRequest, (void*)&clsockfd);
    pthread_detach(id);//分离线程
  }


  return 0;
}
