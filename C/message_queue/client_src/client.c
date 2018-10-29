#include"../message.h"

int main()
{
  int msgid;
  char msg[1024] = {0};
  char rec_msg[1024] = {0};
  if(-1 != (msgid = OpenMsg()))
  {
    printf("OpenMsg success...\n");
  }
  while(1)
  {
    printf("client# ");
    fflush(stdout);
    memset(msg, 0, sizeof(msg));
    fgets(msg, sizeof(msg), stdin);
    SendMsg(msgid, CLIENT_TYPE, msg);
    if(0 == strcmp(msg, "quit\n"))
    {
      printf("Bye...\n");
      break;
    }

    RecMsg(msgid, SERVICE_TYPE, rec_msg);

    printf("service# %s", rec_msg);
    memset(rec_msg, 0, sizeof(rec_msg));
  }
  return 0;
}
