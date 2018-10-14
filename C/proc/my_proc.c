#include<unistd.h>
#include<stdio.h>
int main()
{
  char buf_line[103]={'\0'};
  int i=0;
  while(i<=70)
  {
    buf_line[i]='#';
    printf("\033[43;40m[%-70s] \r\033[5m %d%%",buf_line,i);
    fflush(stdout);
    sleep(1);
    i+=1;
  }
  return 0;
}
