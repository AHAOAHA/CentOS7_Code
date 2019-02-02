#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<termios.h>
#include"service.hpp"

#define ROW 4//定义行为4
#define COL 4//定义列为4
void PrintMap(int array[ROW][COL]);//打印函数
void PrintArr(int array[ROW][COL]);
int Game(int array[ROW][COL], Task* pt);//游戏主体函数
int IsDown(int array[ROW][COL]);//判断游戏是否失败
int IsFull(int array[ROW][COL]);
void Seed(int array[ROW][COL]);//播撒种子
void MoveMap(int array[ROW][COL], char ch);//移动游戏元素
void MovePointW(int array[ROW][COL], int& Flag_Seed);
void MovePointS(int array[ROW][COL], int& Flag_Seed);
void MovePointA(int array[ROW][COL], int& FLag_Seed);
void MovePointD(int array[ROW][COL], int& Flag_Seed);
void CountFuncW(int array[ROW][COL], int& Flag_Seed);
void CountFuncA(int array[ROW][COL], int& Flag_Seed);
void CountFuncS(int array[ROW][COL], int& Flag_Seed);
void CountFuncS(int array[ROW][COL], int& Flag_Seed);
void IsSeedW(int array[ROW][COL], int& FLag_Seed);
void IsSeedS(int array[ROW][COL], int& Flag_Seed);
void IsSeedA(int array[ROW][COL], int& Flag_Seed);
void IsSeedD(int array[ROW][COL], int& Flag_Seed);
void Proc();
int Game(Task* pt);
