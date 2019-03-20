/*************************************************************************
*File Name: HeapSort.cpp
*Author: AHAOAHA
*mail: ahaoaha_@outlook.com
*Created Time: Mon 04 Mar 2019 07:10:50 PM CST
 ************************************************************************/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
#include <algorithm>

void PrintArr(const std::vector<int>& v)
{
  for(auto& e : v)
  {
    cout << e << "  ";
  }
  cout << endl;
}
void _AdjustDown(std::vector<int>& v, size_t parent, size_t len)
{
  size_t l_chr = parent * 2 + 1;  //计算出左孩子的长度
  while(l_chr <= len)
  {
    size_t r_chr = l_chr + 1; //右孩子下标
    size_t biger_chr = l_chr;
    if(r_chr <= len)
    {
      biger_chr = l_chr > r_chr ? l_chr : r_chr;
    }
    if(v[parent] < v[biger_chr])
    {
      std::swap(v[parent], v[biger_chr]);
      parent = l_chr;
      l_chr = l_chr * 2 + 1;
    }
    else
      break;
  }
}

void AdjustDown(std::vector<int>& v, size_t len)
{
  int parent = (len - 1) / 2;
  for(parent; parent >= 0; --parent)
  {
    _AdjustDown(v, parent, len);
    PrintArr(v);
  }
}


void HeapSort(std::vector<int>& v)
{
  //采用向下调整法
  for(int i = v.size() - 1; i >= 0; --i)
  {
    AdjustDown(v, i);  //每进行一次，将v中前n个最大的元素换到堆顶
    std::swap(v[0], v[i]);
  }
  PrintArr(v);
}



int main()
{
  int arr[5] = {3,5,2,7,1};
  std::vector<int> v(arr, arr + 5);
  HeapSort(v);
  return 0;
}
