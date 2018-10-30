/*
简单的2048游戏
w.a.s.d控制上下左右
*/
#include"2048.h"
int Array[ROW][COL] = { 0 };//定义一个二维数组为全局变量，作为游戏主体
int main()
{
	Game(Array);
	return 0;
}
