/*************************************************************************
*File Name: work4.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Tue 25 Dec 2018 12:53:33 PM CST
 ************************************************************************/
//可以不断接受键盘字符，大写字母输出小写字母，小写字母输出大写字母，数字不输出
//输入字符时，缓冲区遗留字符问题
#include <stdio.h>

int main()
{
  char ch;
  char buf[32];
  
  while(1)
  {
    printf("input ch:");
    fgets(buf, sizeof(buf), stdin);
    ch = buf[0];
    if('a' <= ch&&ch <= 'z')
    {
      printf("ch: %c\n", ch+('A'-'a'));
    }
    else if('A' <= ch&& ch <= 'Z')
    {
      printf("ch: %c\n", ch-('A' - 'a'));
    }
    else
    {
      printf("\n");
    }
  }
  return 0;
}
