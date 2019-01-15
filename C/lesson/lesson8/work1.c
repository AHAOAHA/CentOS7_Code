/*************************************************************************
*File Name: work1.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月14日 星期一 12时09分58秒
 ************************************************************************/
/*5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果 
  A选手说：B第二，我第三； 
  B选手说：我第二，E第四； 
  C选手说：我第一，D第二； 
  D选手说：C最后，我第三； 
  E选手说：我第四，A第一； 
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次*/
#include <stdio.h>


void swap(char arr[], int index1, int index2)
{
  char tmp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = tmp;
}

int main()
{
  //1. 产生所有的获奖情况
  //2. 筛选结果
  char arr[5] = {'A', 'B', 'C', 'D', 'E'};

  for(;;)//全排列所有的得奖情况
  {
    if(((arr[2-1]=='B')||(arr[3-1]=='A'))&&\
        ((arr[2-1]=='B')||(arr[4-1]=='E'))&&\
        ((arr[1-1]=='C')||(arr[2-1]=='D'))&&\
        ((arr[5-1]=='C')||(arr[3-1]=='D'))&&\
        ((arr[4-1]=='E')||(arr[1-1]=='A')))
    {
      printf("Right sort: %c, %c, %c, %c, %c\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    }
  }
}

