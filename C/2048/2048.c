#include"2048.h"

//进度条
void Proc()
{
  char buf[100] = {'\0'};
  int i = 0;
  char flag[4] = {'-', '\\', '|', '/'};

  printf("\033[2J");
  printf("\033[0;0H");
  FILE* fp = fopen("./file","r");
  char file;
  while((file = fgetc(fp))!=EOF)
  {
    printf("%c\033[?25l", file);
    usleep(1000);
    fflush(stdout);
  }
  fclose(fp);
  while(i < 70)
  {
    buf[i] = '#';
    printf("          [%-70s] %c \r",buf, flag[i%4]);
    usleep(10000);
    fflush(stdout);
    i += 1;
  }
  printf("\n");
}
//打印函数
void PrintMap(int array[ROW][COL])
{
	int i = 0;
	int j = 0;
	printf("\n");
  printf("\033[2J");
  printf("\033[0;0H");
	for (i = 0; i < ROW; ++i)
	{
		printf("---------------------\n");
		for (j = 0; j < COL; ++j)
		{
			if (0 != array[i][j])
			{
				if (10 > array[i][j])
					printf("|   %d", array[i][j]);
				else if (10 <= array[i][j] && 100>array[i][j])
					printf("|  %d", array[i][j]);
				else if (100 <= array[i][j] && 1000 > array[i][j])
					printf("| %d", array[i][j]);
				else
					printf("|%d", array[i][j]);
			}
			else
				printf("|    ");
		}
		printf("|\n");
	}
	printf("---------------------\n");
}

//判断是否失败 返回0表示未失败 返回1表示失败
int IsDown(int array[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			if (0 == array[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
}

//播种
void Seed(int array[ROW][COL])
{
	int row = 0;
	int col = 0;
	int flag = 0;
	if (IsDown(array))
	{
		printf("你输了！\n");
		return;
	}
	srand((unsigned)time(NULL));//用程序运行时间作为生成随机数种子
	do
	{
		flag = 0;
		row = rand() % ROW;
		col = rand() % COL;
		if (0 == array[row][col])
		{
			array[row][col] = 2;
		}
		else if (2 == array[row][col])
		{
			flag = 1;
		}
	} while (!(2 == array[row][col] && 0 == flag));
}

//移动地图
void MoveMap(int array[ROW][COL])
{
	char point = '0';
	if (IsDown(array))
	{
		printf("你输了！\n");
		return;
	}
	printf("w:up s:down a:left d:right\nq:quit\n");
  //设置不输入回车直接读取字符
  system("stty raw");
	point = getchar();
  system("stty -raw");
	switch(point)
	{
	case 'w':IsSeedW(array);
		MovePointW(array);
		break;
	case 's':IsSeedS(array);
		MovePointS(array);
		break;
	case 'a':IsSeedA(array);
		MovePointA(array);
		break;
	case 'd':IsSeedD(array);
		MovePointD(array);
		break;
  case 'q':
    printf("quit...\r\n\033[?25h");
    exit(0);
	default:printf("非法输入！\n");
		break;
	}
}

struct POS
{
	int row;
	int col;
};

/*
使用两个位置分别标记行不是0的第一位和第二位
若第一位和第二位相等 就让他们相加 结果赋给第一位的位置 并把标记清空 继续向后寻找
若不相等 让把第二位的位置赋给第一位 清楚寻找第二位的标记 继续向后寻找第二位
*/
//向上运算函数W
void CountFuncW(int array[ROW][COL])
{
	int flag_1 = 0;
	int flag = 0;
	struct POS pos;
	struct POS first;
	struct POS second;
	//列遍历二位数组 从上向下
	for (pos.col = 0; pos.col < COL; ++pos.col)
	{
		flag = 0;
		for (pos.row = 0; pos.row < ROW; ++pos.row)
		{
			if (0 != array[pos.row][pos.col] && 0 == flag)
			{
				first.col = pos.col;
				first.row = pos.row;
				flag = 1;
			}
			else if (0 != array[pos.row][pos.col] && 1 == flag)
			{
				second.row = pos.row;
				second.col = pos.col;
				flag_1 = 1;
			}
			if (1 == flag_1)
			{
				if (array[first.row][first.col] == array[second.row][second.col])
				{
					array[first.row][first.col] *= 2;
					array[second.row][second.col] = 0;
					flag = 0;
					Flag_Seed = 1;
				}

				else
				{
					first.col = second.col;
					first.row = second.row;
				}

				flag_1 = 0;
			}
		}
	}
}
void MovePointW(int array[ROW][COL])
{
	struct POS pos;
	struct POS start;
	//运算函数
	CountFuncW(array);

	//列遍历二维数组 从上向下
	for (start.col = 0; start.col < COL; ++start.col)
	{
		pos.col = start.col;
		pos.row = 0;
		for (start.row = 0; start.row < ROW; ++start.row)
		{
			//找出最近的0的位置
			while (0 != array[pos.row][pos.col] && pos.row < ROW)
			{
				++pos.row;
			}
			if (pos.row == ROW)
				continue;

			//在pos下面 如果有位置不是0 就把它换到pos的位置
			if (0 != array[start.row][start.col] && start.row>pos.row)
			{
				array[pos.row][pos.col] = array[start.row][start.col];
				array[start.row][start.col] = 0;
			}
		}
	}
}

void CountFuncS(int array[ROW][COL])
{
	int flag_1 = 0;
	int flag = 0;
	struct POS pos;
	struct POS first;
	struct POS second;
	//列遍历二位数组 从上向下
	for (pos.col = COL - 1; pos.col >= 0; --pos.col)
	{
		flag = 0;
		for (pos.row = ROW - 1; pos.row >= 0; --pos.row)
		{
			if (0 != array[pos.row][pos.col] && 0 == flag)
			{
				first.col = pos.col;
				first.row = pos.row;
				flag = 1;
			}
			else if (0 != array[pos.row][pos.col] && 1 == flag)
			{
				second.row = pos.row;
				second.col = pos.col;
				flag_1 = 1;
			}
			if (1 == flag_1)
			{
				if (array[first.row][first.col] == array[second.row][second.col])
				{
					array[first.row][first.col] *= 2;
					array[second.row][second.col] = 0;
					flag = 0;
					Flag_Seed = 1;
				}

				else
				{
					first.col = second.col;
					first.row = second.row;
				}

				flag_1 = 0;
			}
		}
	}
}
void MovePointS(int array[ROW][COL])
{
	struct POS pos;
	struct POS start;

	CountFuncS(array);
	//列遍历二维数组 从下向上
	for (start.col = COL - 1; start.col >= 0; --start.col)
	{
		pos.col = start.col;
		pos.row = ROW - 1;
		for (start.row = ROW - 1; start.row >= 0; --start.row)
		{
			while (0 != array[pos.row][pos.col] && pos.row >= 0)
			{
				--pos.row;
			}
			if (pos.row == -1)
				continue;
			if (0 != array[start.row][start.col] && start.row<pos.row)
			{
				array[pos.row][pos.col] = array[start.row][start.col];
				array[start.row][start.col] = 0;
			}
		}
	}
}

void CountFuncA(int array[ROW][COL])
{
	int flag_1 = 0;
	int flag = 0;
	struct POS pos;
	struct POS first;
	struct POS second;
	//列遍历二位数组 从上向下
	for (pos.row = 0; pos.row < ROW; ++pos.row)
	{
		flag = 0;
		for (pos.col = 0; pos.col < COL; ++pos.col)
		{
			if (0 != array[pos.row][pos.col] && 0 == flag)
			{
				first.col = pos.col;
				first.row = pos.row;
				flag = 1;
			}
			else if (0 != array[pos.row][pos.col] && 1 == flag)
			{
				second.row = pos.row;
				second.col = pos.col;
				flag_1 = 1;
			}
			if (1 == flag_1)
			{
				if (array[first.row][first.col] == array[second.row][second.col])
				{
					array[first.row][first.col] *= 2;
					array[second.row][second.col] = 0;
					flag = 0;
					Flag_Seed = 1;
				}

				else
				{
					first.col = second.col;
					first.row = second.row;
				}

				flag_1 = 0;
			}
		}
	}
}
void MovePointA(int array[ROW][COL])
{
	struct POS pos;
	struct POS start;

	CountFuncA(array);
	//行遍历二维数组 从左向右
	for (start.row = 0; start.row < ROW; ++start.row)
	{
		pos.row = start.row;
		pos.col = 0;
		for (start.col = 0; start.col < COL; ++start.col)
		{
			//找出最近的0的位置
			while (0 != array[pos.row][pos.col] && pos.row < COL)
			{
				++pos.col;
			}
			if (pos.row == COL)
				continue;

			//在pos后面 如果有位置不是0 就把它换到pos的位置
			if (0 != array[start.row][start.col] && start.col>pos.col)
			{
				array[pos.row][pos.col] = array[start.row][start.col];
				array[start.row][start.col] = 0;
			}
		}
	}
}

void CountFuncD(int array[ROW][COL])
{
	int flag_1 = 0;
	int flag = 0;
	struct POS pos;
	struct POS first;
	struct POS second;
	//列遍历二位数组 从上向下
	for (pos.row = ROW - 1; pos.row >= 0; --pos.row)
	{
		flag = 0;
		for (pos.col = COL - 1; pos.col >= 0; --pos.col)
		{
			if (0 != array[pos.row][pos.col] && 0 == flag)
			{
				first.col = pos.col;
				first.row = pos.row;
				flag = 1;
			}
			else if (0 != array[pos.row][pos.col] && 1 == flag)
			{
				second.row = pos.row;
				second.col = pos.col;
				flag_1 = 1;
			}
			if (1 == flag_1)
			{
				if (array[first.row][first.col] == array[second.row][second.col])
				{
					array[first.row][first.col] *= 2;
					array[second.row][second.col] = 0;
					flag = 0;
					Flag_Seed = 1;
				}

				else
				{
					first.col = second.col;
					first.row = second.row;
				}

				flag_1 = 0;
			}
		}
	}
}
void MovePointD(int array[ROW][COL])
{
	struct POS pos;
	struct POS start;

	CountFuncD(array);
	//行遍历二维数组 从右向左
	for (start.row = ROW - 1; start.row >= 0; --start.row)
	{
		pos.row = start.row;
		pos.col = COL - 1;
		for (start.col = COL - 1; start.col >= 0; --start.col)
		{
			while (0 != array[pos.row][pos.col] && pos.col >= 0)
			{
				--pos.col;
			}
			if (pos.col == -1)
				continue;
			if (0 != array[start.row][start.col] && start.col<pos.col)
			{
				array[pos.row][pos.col] = array[start.row][start.col];
				array[start.row][start.col] = 0;
			}
		}
	}
}

//判断是否需要生成种子
int Flag_Seed = 1;//设置全局变量作为是否生成种子的标记
void IsSeedW(int array[ROW][COL])
{
	int flag_first_0 = 0;//标记是否找到第一个0
	struct POS start;

	//列遍历二维数组 从上向下
	for (start.col = 0; start.col < COL; ++start.col)
	{
		flag_first_0 = 0;//当完成一列的对比时 将flag_first_0该为0
		for (start.row = 0; start.row < ROW; ++start.row)
		{
			if (0 == array[start.row][start.col] && 0 == flag_first_0)
			{
				flag_first_0 = 1;//表示找到第一个0
			}
			else if (0 != array[start.row][start.col] && 1 == flag_first_0)
			{
				Flag_Seed = 1;
				return;
			}
		}
	}
}
void IsSeedS(int array[ROW][COL])
{
	int flag_first_0 = 0;//标记是否找到第一个0
	struct POS start;

	//列遍历二维数组 从上向下
	for (start.col = COL - 1; start.col >= 0; --start.col)
	{
		flag_first_0 = 0;//当完成一列的对比时 将flag_first_0该为0
		for (start.row = ROW - 1; start.row >= 0; --start.row)
		{
			if (0 == array[start.row][start.col] && 0 == flag_first_0)
			{
				flag_first_0 = 1;//表示找到第一个0
			}
			else if (0 != array[start.row][start.col] && 1 == flag_first_0)
			{
				Flag_Seed = 1;
				return;
			}
		}
	}
}
void IsSeedA(int array[ROW][COL])
{
	int flag_first_0 = 0;//标记是否找到第一个0
	struct POS start;

	//列遍历二维数组 从上向下
	for (start.row = 0; start.row < ROW; ++start.row)
	{
		flag_first_0 = 0;//当完成一列的对比时 将flag_first_0该为0
		for (start.col = 0; start.col < COL; ++start.col)
		{
			if (0 == array[start.row][start.col] && 0 == flag_first_0)
			{
				flag_first_0 = 1;//表示找到第一个0
			}
			else if (0 != array[start.row][start.col] && 1 == flag_first_0)
			{
				Flag_Seed = 1;
				return;
			}
		}
	}
}
void IsSeedD(int array[ROW][COL])
{
	int flag_first_0 = 0;//标记是否找到第一个0
	struct POS start;

	//列遍历二维数组 从上向下
	for (start.row = ROW - 1; start.row >= 0; --start.row)
	{
		flag_first_0 = 0;//当完成一列的对比时 将flag_first_0该为0
		for (start.col = COL - 1; start.col >= 0; --start.col)
		{
			if (0 == array[start.row][start.col] && 0 == flag_first_0)
			{
				flag_first_0 = 1;//表示找到第一个0
			}
			else if (0 != array[start.row][start.col] && 1 == flag_first_0)
			{
				Flag_Seed = 1;
				return;
			}
		}
	}
}
//////////////////////////游戏主体函数
int Game(int array[ROW][COL])
{
  Proc();
	printf("游戏开始！\n");
  usleep(500000);
	while (!IsDown(array))
	{
		if (1 == Flag_Seed)
		{
			Seed(array);
			Flag_Seed = 0;
		}
		PrintMap(array);
		MoveMap(array);
	}
	return 0;
}
