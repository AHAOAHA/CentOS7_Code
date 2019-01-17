/*************************************************************************
*File Name: work2.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月17日 星期四 12时32分11秒
 ************************************************************************/
/*
日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯 
的一个。以下为4个嫌疑犯的供词。 
A说：不是我。 
B说：是C。 
C说：是D。 
D说：C在胡说 
已知3个人说了真话，1个人说的是假话。 
现在请根据这些信息，写一个程序来确定到底谁是凶手。
*/
#include <stdio.h>

int main()
{
  char killer;

  for(killer = 'A'; killer <= 'D'; ++killer)
  {
    if(((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
    {
      printf("killer: %c.\n", killer);
    }
  }
}
