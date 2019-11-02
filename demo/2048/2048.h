#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<termios.h>

#define ROW 4//定义行为4
#define COL 4//定义列为4
void PrintMap(int array[ROW][COL]);//打印函数
int Game(int array[ROW][COL]);//游戏主体函数
int IsDown(int array[ROW][COL]);//判断游戏是否失败
int IsFull(int array[ROW][COL]);
void Seed(int array[ROW][COL]);//播撒种子
void MoveMap(int array[ROW][COL]);//移动游戏元素
void MovePointW(int array[ROW][COL]);
void MovePointS(int array[ROW][COL]);
void MovePointA(int array[ROW][COL]);
void MovePointD(int array[ROW][COL]);
void CountFuncW(int array[ROW][COL]);
void CountFuncA(int array[ROW][COL]);
void CountFuncS(int array[ROW][COL]);
void IsSeedW(int array[ROW][COL]);
void IsSeedS(int array[ROW][COL]);
void IsSeedA(int array[ROW][COL]);
void IsSeedD(int array[ROW][COL]);
void Proc();
extern int Flag_Seed;


