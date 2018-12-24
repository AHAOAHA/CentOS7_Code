/*************************************************************************
*File Name: work4.c
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 24 Dec 2018 07:14:34 PM CST
 ************************************************************************/
//验证所有括号都是成对出现
#include <stdio.h>
#include <assert.h>

struct stack
{
  char data[1024];
  size_t size;
};

void stackInit(struct stack *s)
{
  s->size = 0;
}
char stackTop(struct stack *s)
{
  return s->data[s->size - 1];
}

void stackPush(struct stack *s, char ch)
{
  assert(s->size < 1024);
  s->data[s->size] = ch;
  s->size += 1;
}

void stackPop(struct stack *s)
{
  assert(s->size > 0);
  s->size -= 1;
}


int main()
{
  struct stack s;
  stackInit(&s);
  int i = 0;
  char buf[1024] = {'\0'};
  printf("input:");
  fgets(buf, sizeof(buf) - 1, stdin);

  while(buf[i] != '\0')
  {
    switch(buf[i])
    {
      case '(':
        stackPush(&s, '(');
        break;
      case '[':
        stackPush(&s, '[');
        break;
      case '{':
        stackPush(&s, '{');
        break;
      case ')':
        if(stackTop(&s) != '(')
        {
          printf("no ...\n");
          return 0;
        }
        stackPop(&s);
        break;
      case ']':
        if(stackTop(&s) != '[')
        {
          printf("no ...\n");
          return 0;
        }
        stackPop(&s);
        break;
      case '}':
        if(stackTop(&s) != '{')
        {
          printf("no ...\n");
          return 0;
        }
        stackPop(&s);
        break;
      default:
        break;
    }
    ++i;
  }

  if(s.size != 0)
  {
    printf("no ...\n");
    return 0;
  }

  printf("yes ...\n");
  return 0;
}
