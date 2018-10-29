#include"../message.h"

int main()
{
  int msgid;
  char rec_msg[1024] = {0};
  char msg[1024] ={0};
  if(-1 != (msgid = CreatMsg()))
  {
    printf("CreatMsg success...\n");
  }
  if(-1 != (msgid = OpenMsg()))
  {
    printf("OpenMsg success...\n");
  } 
  while(1)
  {
    RecMsg(msgid, CLIENT_TYPE, rec_msg);
    if(0 == strcmp(rec_msg, "quit\n"))
    {
      printf("quit signal,Bye...\n");
      break;
    }
    printf("client$ %s",rec_msg);
    memset(rec_msg, 0, sizeof(rec_msg));

    printf("service# ");
    fflush(stdout);
    memset(msg, 0, sizeof(msg));
    fgets(msg, sizeof(msg), stdin);
    SendMsg(msgid, SERVICE_TYPE, msg);
  }

  DestoryMsg(msgid);
  return 0;
}

