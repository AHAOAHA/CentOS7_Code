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



void insert_head(int map[ROW][COL],struct snake_node** head,struct pos pos)
{
  struct snake_node* new_head = (struct snake_node*)malloc(sizeof(struct snake_node));
  new_head->_x = pos._x;
  new_head->_y = pos._y;
  new_head->_next = *head;
  map[new_head->_x][new_head->_y] = 2;
  *head = new_head;
}

void grow_up(int map[ROW][COL],struct snake_node** head, int status)
{
  struct pos pos;
  switch(status)
  {
    case U:
           pos._x = (*head)->_x - 1;
           pos._y = (*head)->_y;
          insert_head(map,head,pos);
      break;
    case D:
           pos._x = (*head)->_x + 1;
           pos._y = (*head)->_y;
          insert_head(map,head,pos);
      break;
    case R:
           pos._x = (*head)->_x;
           pos._y = (*head)->_y + 1;
          insert_head(map,head,pos);
      break;
    case L:
           pos._x = (*head)->_x;
           pos._y = (*head)->_y - 1;
          insert_head(map,head,pos);
      break;
    default:
      break;
  }
  create_food(map);
}

void control_snake(int map[ROW][COL], struct snake_node** head, int* status)
{
  //控制蛇身
}

void move_up(int map[ROW][COL],struct snake_node **head)
{
  if(1==map[(*head)->_x - 1][(*head)->_y])
  {
    printf("碰到墙了\n");
    exit(1);
  }
  else if(3 == map[(*head)->_x - 1][(*head)->_y])
  {
    //吃到食物
    grow_up(map,head,U);
  }
  struct snake_node *ptr = *head;
  struct snake_node * ppre = ptr;
  struct snake_node *new_head = (struct snake_node*)malloc(sizeof(struct snake_node));
  new_head->_x = ptr->_x - 1;
  new_head->_y = ptr->_y;
  map[new_head->_x][new_head->_y] = 2;
  new_head->_next = *head;
  *head = new_head;

  while(ptr->_next)
  {
    ptr = ptr->_next;
    if(NULL != ptr->_next)
      ppre = ppre->_next;
  }

  ppre->_next = NULL;

  map[ptr->_x][ptr->_y] = 0;
  free(ptr);
}

void move_down(int map[ROW][COL],struct snake_node **head)
{
  if(1 == map[(*head)->_x + 1][(*head)->_y])
  {
    printf("碰到墙了\n");
    exit(1);
  }
  else if(3 == map[(*head)->_x + 1][(*head)->_y])
  {
    //吃到食物
    grow_up(map,head,D);
  }

  struct snake_node *ptr = *head;
  struct snake_node *ppre = ptr;
  struct snake_node *new_head = (struct snake_node*)malloc(sizeof(struct snake_node));
  new_head->_x = ptr->_x + 1;
  new_head->_y = ptr->_y;
  map[new_head->_x][new_head->_y] = 2;
  new_head->_next = *head;
  *head = new_head;

  while(ptr->_next)
  {
    ptr = ptr->_next;
    if(NULL != ptr->_next)
      ppre = ppre->_next;
  }
  ppre->_next = NULL;

  map[ptr->_x][ptr->_y] = 0;
  free(ptr);
}


void move_right(int map[ROW][COL],struct snake_node **head)
{
  if(1 == map[(*head)->_x][(*head)->_y + 1])
  {
    printf("碰到墙了\n");
    exit(1);
  }
  else if(3 == map[(*head)->_x][(*head)->_y + 1])
  {
    //吃到食物
    grow_up(map,head,R);
  }
  struct snake_node *ptr = *head;
  struct snake_node *ppre = ptr;
  struct snake_node *new_head = (struct snake_node*)malloc(sizeof(struct snake_node));
  new_head->_x = ptr->_x;
  new_head->_y = ptr->_y + 1;
  map[new_head->_x][new_head->_y] = 2;
  new_head->_next = *head;
  *head = new_head;

  while(ptr->_next)
  {
    ptr = ptr->_next;
    if(NULL != ptr->_next)
      ppre = ppre->_next;
  }
  ppre->_next = NULL;

  map[ptr->_x][ptr->_y] = 0;
  free(ptr);
}



void move_left(int map[ROW][COL],struct snake_node **head)
{
  if(1 == map[(*head)->_x][(*head)->_y - 1])
  {
    printf("碰到墙了\n");
    exit(1);
  }
  else if(3 == map[(*head)->_x][(*head)->_y - 1])
  {
    //吃到食物
    grow_up(map,head,L);
    
  }
  struct snake_node *ptr = *head;
  struct snake_node *ppre = ptr;
  struct snake_node *new_head = (struct snake_node*)malloc(sizeof(struct snake_node));
  new_head->_x = ptr->_x;
  new_head->_y = ptr->_y - 1;
  map[new_head->_x][new_head->_y] = 2;
  new_head->_next = *head;
  *head = new_head;

  while(ptr->_next)
  {
    ptr = ptr->_next;
    if(NULL != ptr->_next)
      ppre = ppre->_next;
  }
  ppre->_next = NULL;

  map[ptr->_x][ptr->_y] = 0;
  free(ptr);
}



void snake_move(int map[ROW][COL], struct snake_node** head,int status)
{
  assert(head);

  switch(status)
  {
    case U:move_up(map, head);
      break;
    case D:move_down(map, head);
      break;
    case R:move_right(map, head);
      break;
    case L:move_left(map, head);
      break;
    default:
      exit(0);
      break;
  }
}

void create_food(int map[ROW][COL])
{
  int food_x = 0;
  int food_y = 0;
  srand(time(NULL));
  food_x = 1 + rand() % (ROW - 1 - 1);
  food_y = 1 + rand() % (COL - 1 - 1);
  map[food_x][food_y] = 3;

}

snake_node *create_snake(int map[ROW][COL])
{
  int i = 3;
  struct snake_node *head;
  head =(struct snake_node*)malloc(sizeof(struct snake_node));
  srand(time(NULL));//设置随机数种子
  head->_x = 3 + rand() % (ROW - 2 - 3);
  head->_y = 3 + rand() % (COL - 2 - 3);
  head->_next = (struct snake_node*)malloc(sizeof(struct snake_node));
  head->_next->_x = head->_x + 1;
  head->_next->_y = head->_y;
  map[head->_x][head->_y] = 2;
  map[head->_next->_x][head->_next->_y] = 2;
  head->_next->_next = NULL;

  
  return head;
}

void print(int map[ROW][COL])
{
  int row = 0;
  int col = 0;
  for(row = 0; row < ROW; ++row)
  {
    for(col = 0; col<COL; ++col)
    {
      printf("%d ",map[row][col]);
    }
    printf("\n");
  }
}

void init_border(int map[ROW][COL])
{
  int row = 0;
  int col = 0;
  for(row = 0; row < ROW; ++row)
  {
    map[row][0] = 1;
    map[row][COL - 1] = 1;
  }
  for(col = 0; col < COL; ++col)
  {
    map[0][col] = 1;
    map[ROW - 1][col] = 1;
  }
}

int game()
{
  struct snake_node* snake_head;
  int status = U;
  int map[ROW][COL] = {0};//定义游戏地图,0为游戏地图，1为边框，2为蛇身，3为食物
  init_border(map);//初始化游戏边框
  snake_head = create_snake(map);//创建蛇身
  create_food(map);
  control_snake(map,&snake_head,&status);
  
  return 0;
}
