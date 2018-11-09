#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<unistd.h>
#include<wait.h>

#define ROW 10//行
#define COL 10//列

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

void init_border(int map[ROW][COL]);//初始化游戏边界
void print(int map[ROW][COL]);//打印函数
int game();//游戏主体函数
snake_node* create_snake(int map[ROW][COL]);//创建蛇身
void create_food(int map[ROW][COL]);//创建食物
void snake_move(int map[ROW][COL],struct snake_node** head,int status);//移动蛇身
void move_up(int map[ROW][COL],struct snake_node **head);
void move_down(int map[ROW][COL],struct snake_node **head);
void move_right(int map[ROW][COL],struct snake_node **head);
void move_left(int map[ROW][COL],struct snake_node **head);
void control_snake(int map[ROW][COL], struct snake_node** head,int* status);
void grow_up(int map[ROW][COL], struct snake_node** head,int status);
void insert_head(int map[ROW][COL],struct snake_node** head,struct pos pos);
