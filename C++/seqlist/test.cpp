#include"seqlist.h"
int main()
{
  SeqList s1;
  int array[5] = {3,2,1,4,5};
  SeqList s2(array, 5);
  s2.print();
  s2.push_back(6);
  s2.print();
  s2.push_front(7);
  s2.push_front(0);
  s2.select_sort_OP();

  printf("%d\n",s2.binary_search_R(0,7,5));
  s2.print();
  return 0;
}
