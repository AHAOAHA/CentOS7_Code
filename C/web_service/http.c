/*************************************************************************
*File Name: http.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Tue Dec 25 23:18:55 2018
 ************************************************************************/
#include "http.h"
#include "service.h"

int GetLine(int clsockfd, char *buf, int len)
{
  assert(buf);
  char ch = '\0';
  int i = 0;
  while(i < len - 1 && ch != '\n')
  {
    if(recv(clsockfd, &ch, 1, 0) > 0)
    {
      if(ch == '\r')
      {
        if(recv(clsockfd, &ch, 1, MSG_PEEK) > 0 && ch == '\n')//MSG_PEEK:不改变读取指针式读取
          recv(clsockfd, &ch, 1, 0);
        else
          ch = '\n';
      }
      buf[i++] = ch;
    }
  }
  buf[i] = '\0';
  return i;
}

int handle(int clsockfd)
{
  char buf[SIZE];//保存客户端请求
  char method[64];//保存方法
  char url[SIZE];//保存url
  int i = 0;
  int j = 0;
  int ret;
  char* query_string = NULL;
  char path[SIZE];
  

  if(GetLine(clsockfd, buf, sizeof(buf)) <= 0)//这里仅读取浏览器请求的第一行
  {
    PrintLog("GetLine error");
    ret = 1;
    goto end;
  }

  
  //GET /XX/YY/ZZ HTTP/1.0
  //提取方法:遇到空格，则之前读取到的字符就是方法
  while((i < (sizeof(buf) - 1)) && (j < (sizeof(method) - 1)) && (buf[j] != ' '))
  {
    method[j++] = buf[i++];
  }
  method[j] = '\0';

  //strcasecmp:忽略大小写比较字符串
  //都不为0时则退出
  if(strcasecmp(method, "GET") && strcasecmp(method, "POST"))
  {
    PrintLog("request method fail");
    ret = 2;
    goto end;
  }



  //此时buf[i] = ' '->GET后面的空格
  //过滤空格，使i指向资源有效路径
  while(i < sizeof(buf) && buf[i] == ' ')
    ++i;
  //此时i-> /XX/YY/ZZ?a=a&b=b&c=c HTTP/1.0

  //提取url，分离参数
  j = 0;
  while(i < sizeof(buf) && j < sizeof(url) - 1 && buf[i] != ' ')
  {
    url[j++] = buf[i++];
  }

  url[j] = '\0';

  //GET方法:提取参数给query_string:提取出/XX/YY/ZZ
  if(strcasecmp(method, "GET") == 0)
  {
    //处理方法
    query_string = url;

    //让query_string指向?处,?后面即就是参数
    while(*query_string != '\0' && *query_string != '?')
    {
      query_string++;
    }

    //如果有?表示有参数，使query_string指向参数处
    
    if(*query_string == '?')
    {
      *query_string = '\0';
      query_string++;
    }
  }

  //转换路径/XX/YY/ZZ -> wwwroot/XX/YY/ZZ
  sprintf(path, "wwwroot%s", url);
  if(path[strlen(path) - 1] == '/')//如果是一个目录就拼接上主页
  {
    strcat(path, "index.html");
  }

  //检测资源是否存在
  struct stat st;
  if(stat(path, &st) == -1)
  {
    //请求资源页面不存在,此处该返回404页面
    ClearHeader(clsockfd);//将socket中的内容全部读取掉
    ShowError(clsockfd, 404);
    PrintLog(path);
    ret = 3;
    goto end;
  }
  else
  {
    if(S_ISDIR(st.st_mode))//是一个目录文件
    {
      strcat(path, "/index.html");
    }
    else//普通文件
    {

    }
  }

  ret = ClearHeader(clsockfd);//将socket中的内容全部读取掉
  ret = ShowWWW(clsockfd, path, st.st_size);

end:
  close(clsockfd);
  return ret;

}


int ClearHeader(int clsockfd)
{
  char line[SIZE];
  int ret = -1;
  do
  { 
    ret = GetLine(clsockfd, line, SIZE);
  }while(ret != 1 && strcmp(line, "\n") != 0);

  return ret;
}

//返回正确页面
int ShowWWW(int clsockfd, char *path, ssize_t size)
{
  int ret = -1;
  int fd = open(path, O_RDONLY);//打开目标文件
  if(fd < 0)
  {
    PrintLog("open file fail");
    ret = 8;
    goto end;
  }

  char line[SIZE*10];

  //响应报头
  sprintf(line, "HTTP/1.0 200 OK\n");
  send(clsockfd, line, strlen(line), 0);
  send(clsockfd, "\r\n", 2, 0);
  if(sendfile(clsockfd, fd, NULL, size) < 0)
  {
    PrintLog("send file fail");
    ShowError(clsockfd, 503);
    ret = 9;
    goto end;
  }
end:
  close(fd);
  return ret;

}

void ShowError(int clsockfd, int error_code)
{
  switch(error_code)
  {
    case 404:
      ErrorRequest("wwwroot/404.html", "HTTP/1.0 404 Not Found\n", clsockfd);
      break;
    case 503:
      ErrorRequest("wwwroot/503.html", "HTTP/1.0 503 Not Found\n", clsockfd);
      break;
  }
}

void ErrorRequest(const char *path, const char *head, int clsockfd)
{
  struct stat st;
  if(stat(path, &st) < 0)
  {
    return;
  }
  int fd = open(path, O_RDONLY);

  //响应报头
  send(clsockfd, head, strlen(head), 0);
  const char *content_type = "Content-Type:text/html;charset=ISO-8859-1\r\n";
  send(clsockfd, content_type, strlen(content_type), 0);
  send(clsockfd, "\r\n", 2, 0);

  sendfile(clsockfd, fd, NULL, st.st_size);
  close(fd);
}
