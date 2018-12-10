#include"./snake.h"

struct snake_node* snake_head;
int status = U;
int map[ROW][COL] = {0};//定义游戏地图,0为游戏地图，1为边框，2为蛇身，3为食物

pthread_mutex_t mutex;
pthread_cond_t cond;

void insert_head(struct pos pos)
{
  struct snake_node* new_head = (struct snake_node*)malloc(sizeof(struct snake_node));
  new_head->_x = pos._x;
  new_head->_y = pos._y;
  new_head->_next = snake_head;
  map[new_head->_x][new_head->_y] = 2;
  snake_head = new_head;
}

void grow_up()
{
  struct pos pos;
  switch(status)
  {
    case U:
           pos._x = (snake_head)->_x - 1;
           pos._y = (snake_head)->_y;
          insert_head(pos);
      break;
    case D:
           pos._x = (snake_head)->_x + 1;
           pos._y = (snake_head)->_y;
          insert_head(pos);
      break;
    case R:
           pos._x = (snake_head)->_x;
           pos._y = (snake_head)->_y + 1;
          insert_head(pos);
      break;
    case L:
           pos._x = (snake_head)->_x;
           pos._y = (snake_head)->_y - 1;
          insert_head(pos);
      break;
    default:
      break;
  }
  create_food();
}

void* PthreadConPoint(void* arg)
{
  char tmp;
  disable_terminal_return();
  while(1)
  {
	  tmp = getchar();
    
    pthread_mutex_lock(&mutex);
    switch(tmp)
    {
      case 'a':
        if(status != 4)
          status = 3;
        break;
      case 'w':
        if(status != 2)
        status = 1;
        break;
      case 's':
        if(status != 1)
          status = 2;
        break;
      case 'd':
        if(status != 3)
        status = 4;
        break;
      default:
        break;
    }

    pthread_mutex_unlock(&mutex);
  }
  return arg;
}

void* PthreadMovSnake(void* arg)
{
  while(1)
  {
    pthread_mutex_lock(&mutex);
    snake_move();
    print();
    pthread_mutex_unlock(&mutex);
    usleep(100000);
  }
  return arg;
}
void control_snake()
{
  //控制蛇身
  //这里需要采用多线程控制，暂停之，待学习多线程之后继续进行
  pthread_t con_point;
  pthread_create(&con_point, NULL, PthreadConPoint, NULL);
  pthread_detach(con_point);
  pthread_t mov_snake;
  pthread_create(&mov_snake, NULL, PthreadMovSnake, NULL);
  pthread_detach(mov_snake);
}

void move_up()
{
  if(1==map[(snake_head)->_x - 1][(snake_head)->_y])
  {
    printf("碰到墙了\n");
    exit(1);
  }
  else if(3 == map[(snake_head)->_x - 1][(snake_head)->_y])
  {
    //吃到食物
    grow_up();
  }
  else if(2 == map[(snake_head)->_x - 1][(snake_head)->_y])
  {
    printf("吃自己了\n");
    exit(1);
  }
  else
  {
    struct snake_node *ptr = snake_head;
    struct snake_node * ppre = ptr;
    struct snake_node *new_head = (struct snake_node*)malloc(sizeof(struct snake_node));
    new_head->_x = ptr->_x - 1;
    new_head->_y = ptr->_y;
    map[new_head->_x][new_head->_y] = 2;
    new_head->_next = snake_head;
    snake_head = new_head;
    
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
}

void move_down()
{
  if(1 == map[(snake_head)->_x + 1][(snake_head)->_y])
  {
    printf("碰到墙了\n");
    exit(1);
  }
  else if(3 == map[(snake_head)->_x + 1][(snake_head)->_y])
  {
    //吃到食物
    grow_up();
  }
  else if(2 == map[(snake_head)->_x + 1][(snake_head)->_y])
  {
    printf("吃自己了\n");
    exit(1);
  }
  else
  {

    struct snake_node *ptr = snake_head;
    struct snake_node *ppre = ptr;
    struct snake_node *new_head = (struct snake_node*)malloc(sizeof(struct snake_node));
    new_head->_x = ptr->_x + 1;
    new_head->_y = ptr->_y;
    map[new_head->_x][new_head->_y] = 2;
    new_head->_next = snake_head;
    snake_head = new_head;
    
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
}


void move_right()
{
  if(1 == map[(snake_head)->_x][(snake_head)->_y + 1])
  {
    printf("碰到墙了\n");
    exit(1);
  }
  else if(3 == map[(snake_head)->_x][(snake_head)->_y + 1])
  {
    //吃到食物
    grow_up();
  }
  else if(2 == map[(snake_head)->_x][(snake_head)->_y + 1])
  {
    printf("吃自己了\n");
    exit(1);
  }
  else
  {
    struct snake_node *ptr = snake_head;
    struct snake_node *ppre = ptr;
    struct snake_node *new_head = (struct snake_node*)malloc(sizeof(struct snake_node));
    new_head->_x = ptr->_x;
    new_head->_y = ptr->_y + 1;
    map[new_head->_x][new_head->_y] = 2;
    new_head->_next = snake_head;
    snake_head = new_head;
    
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
}



void move_left()
{
  if(1 == map[(snake_head)->_x][(snake_head)->_y - 1])
  {
    printf("碰到墙了\n");
    exit(1);
  }
  else if(3 == map[(snake_head)->_x][(snake_head)->_y - 1])
  {
    //吃到食物
    grow_up();
    
  }
  else if(2 == map[(snake_head)->_x][(snake_head)->_y - 1])
  {
    printf("吃自己了\n");
    exit(1);
  }
  else
  {
    struct snake_node *ptr = snake_head;
    struct snake_node *ppre = ptr;
    struct snake_node *new_head = (struct snake_node*)malloc(sizeof(struct snake_node));
    new_head->_x = ptr->_x;
    new_head->_y = ptr->_y - 1;
    map[new_head->_x][new_head->_y] = 2;
    new_head->_next = snake_head;
    snake_head = new_head;
    

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
}



void snake_move()
{

  switch(status)
  {
    case U:move_up();
      break;
    case D:move_down();
      break;
    case R:move_right();
      break;
    case L:move_left();
      break;
    default:
      exit(0);
      break;
  }
}

void create_food()
{
  int food_x = 0;
  int food_y = 0;
  srand(time(NULL));
  do
  {
    food_x = 1 + rand() % (ROW - 1 - 1);
    food_y = 1 + rand() % (COL - 1 - 1);
  }while(map[food_x][food_y] != 0);
  
  map[food_x][food_y] = 3;

}

snake_node *create_snake()
{
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

void print()
{
  int row = 0;
  int col = 0;
  printf("\033[2J");
  printf("\033[0;0H");
  for(row = 0; row < ROW; ++row)
  {
    for(col = 0; col<COL; ++col)
    {
      if(map[row][col] == 0)
        printf(" ");
      else if(map[row][col] == 1)
        printf("#");
      else if(map[row][col] == 3)
        printf("*");
      else
        printf("*");


    }
    printf("\n");
  }

  printf("w:up a:left s:down d:right Author: AHOAHA\n");
}

void init_border()
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
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond, NULL);
  init_border();//初始化游戏边框
  snake_head = create_snake();//创建蛇身
  create_food();
  control_snake();
  while(1);
  return 0;
}
