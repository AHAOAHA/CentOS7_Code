#include"./message.h"

int CreatMsg()//创建消息队列,成功返回消息队列msgid,失败返回-1
{
  umask(0);
  return msgget(ftok(PATHNAME, PRO_ID),IPC_CREAT | IPC_SET | 0666);
}

int OpenMsg()//打开消息队列
{
  return msgget(ftok(PATHNAME, PRO_ID),IPC_CREAT);
}

int SendMsg(int msgid,long who ,char* msg)
{
  struct msg_buf buf;
  buf.type = who;
  strcpy(buf.date, msg);
  if(0 > msgsnd(msgid, (void*)&buf,sizeof(buf.date),0))
  {
    perror("msgsnd");
    return -1;
  }
  return 0;
}

int RecMsg(int msgid, long who, char  msg[])//从消息队列接受消息
{
  struct msg_buf buf;
  buf.type = who;
  printf("Please wait...\n");
  if(-1 == msgrcv(msgid, (void*)&buf, sizeof(buf.date), buf.type,0))
  {
    return -1;
  }
  strcpy(msg, buf.date);
  return 0;
}



int DestoryMsg(const int msgid)//删除消息队列，成功返回0，失败返回-1
{
  return msgctl(msgid, IPC_RMID, NULL);
}
