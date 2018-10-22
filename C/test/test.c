#include<stdio.h>
#include<string.h>
int main()
{
  char* str = "hello world i am a boy\n";
  char* argv[10] = {NULL};
  int i = 0;
  char* buf = " ";
  char* p;
  printf("%s\n",strtok(str," "));
  while(p = strtok(NULL," "))
  {
    printf("%s\n",p);
  }
  return 0;
}
