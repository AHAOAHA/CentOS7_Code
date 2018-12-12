#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<unistd.h>
#include<wait.h>
#include<pthread.h>
#include <termios.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

#define ROW 28//行
#define COL 104//列
//#define ROW 10
//#define COL 10

#define U 1//带表蛇的状态 up
#define D 2//down
#define L 3//Left
#define R 4//right

typedef struct pos
{
  int _x;
  int _y;
}pos;
typedef struct snake_node//创建蛇身结构体
{
  int _x;
  int _y;
  struct snake_node *_next;
}snake_node;

void init_border();//初始化游戏边界
void print();//打印函数
int game();//游戏主体函数
snake_node* create_snake();//创建蛇身
void create_food();//创建食物
void snake_move();//移动蛇身
void move_up();
void move_down();
void move_right();
void move_left();
void control_snake();
void grow_up();
void insert_head(struct pos pos);

void restore_terminal_settings(void);
void disable_terminal_return(void);

