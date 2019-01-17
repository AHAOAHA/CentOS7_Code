/*************************************************************************
*File Name: work3.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: 2019年01月17日 星期四 12时45分12秒
 ************************************************************************/
//打印杨辉三角
#include <stdio.h>


void Print(int arr[5][5])
{
    int i = 0;
      int j = 0;
        for (i = 0; i < 5; i++)
        {
              for (j = 0; j <= i; j++)
              {
                      printf("%d",arr[i][j]);
                          
              }
                  printf("\n");
                    
        }

}
int main()
{
  int arr[5][5] = {0};
  int i = 0;
  for(i = 0; i < 5; ++i)
  {
    arr[i][0] = 1;
    arr[i][i] = 1;
  }

  int j = 0;
  for(i = 2; i < 5; ++i)
  {
    for(j = 1; j < i; j++)
    {
      arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
    }
  }

  Print(arr);
  return 0;
}
