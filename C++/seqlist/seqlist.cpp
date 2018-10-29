#include"./seqlist.h"

SeqList::SeqList(size_t capacity)
  :_capacity(capacity)
   ,_size(0)
{
  _ptr = new DateType[_capacity];
}

SeqList::SeqList(DateType* array, size_t size)
  :_capacity(size + 3)
   ,_size(size)
{
  _ptr = new DateType[_capacity];
  size_t i = 0;
  for(i = 0;i < _size;++i)
  {
    _ptr[i] = array[i];
  }
}
SeqList::~SeqList()
{
  delete[] _ptr;
  _capacity = 0;
  _size = 0;
  _ptr = NULL;
}

void SeqList::push_back(DateType data)
{
  if(!empty())
  {
    printf("capacity == size...\n");
    return;
  }

  _ptr[_size] = data;
  ++_size;
}

void SeqList::pop_back()
{
  --_size;
}

void SeqList::push_front(DateType data)
{
  if(!empty())
  {
    printf("size == capacity...\n");
    return;
  }

  int i = _size;
  for(i = _size;i > 0; --i)
    swap(_ptr[i-1],_ptr[i]);
  _ptr[0] = data;
  ++_size;
}

void SeqList::pop_front()
{
  size_t i = 0;
  for(i = 0; i < _size; ++i)
    swap(_ptr[i],_ptr[i+1]);
  --_size;
}

int SeqList::find(DateType data)
{
  size_t i = 0;
  for(i = 0;i<_size;++i)
  {
    if(data == _ptr[i])
      return i;
  }
  return -1;
}

void SeqList::insert_pos(size_t pos, DateType data)
{
  if(pos > _capacity)
  {
    printf("pos error...\n");
    return;
  }
  if(!empty())
  {
    printf("full...\n");
    return;
  }

  size_t i = _size;
  for(i = _size; i > pos; --i)
    swap(_ptr[i - 1], _ptr[i]);
  _ptr[pos] = data;
  ++_size;
}

void SeqList::erase(size_t pos)
{
  size_t i = pos;
  for(i = pos; i<_size; ++i)
    swap(_ptr[i], _ptr[i + 1]);
  --_size;
}

void SeqList::remove_all()
{
  _size = 0;
}
size_t SeqList::size()
{
  return _size;
}

void SeqList::swap(DateType& data1,DateType& data2)
{
  DateType tmp = data1;
  data1 = data2;
  data2 = tmp;
}
void SeqList::bubble_sort()
{
  size_t i = 0;
  size_t j = 0;
  for(i = 0;i < _size - 1; ++i)
  {
    for(j = 0;j < _size - 1 - i; ++j)
    {
      if(_ptr[j] > _ptr[j + 1])
        swap(_ptr[j],_ptr[j + 1]);
    }
  }
}

void SeqList::select_sort()
{
  size_t max = 0;
  size_t i = 0;
  size_t j = 0;
  for(i = 0;i < _size - 1; ++i)
  {
    for(j = 0;j < _size - 1 - i; ++j)
    {
      if(_ptr[j] > _ptr[max])
        max = j;
    }
    swap(_ptr[max], _ptr[_size - i - 1]);
  }

}

void SeqList::select_sort_OP()
{
  size_t max = 0;
  size_t min = 0;
  size_t left = 0;
  size_t right = _size - 1;
  size_t i = 0;
  while(left < right)
  {
    max = left;
    min = left;
    for(i = left;i<= right; ++i)
    {
      if(_ptr[max]< _ptr[i])
        max = i;
      if(_ptr[min]> _ptr[i])
        min = i;
    }
    if(max == left && min == right)
    {
      swap(_ptr[min],_ptr[left]);
    }
    else
    {
      swap(_ptr[max], _ptr[right]);
      swap(_ptr[min],_ptr[left]);
    }
    ++left;
    --right;
    print();
  }
}
void SeqList::print()
{
  size_t i = 0;
  for(i = 0;i < _size; ++i)
    printf("%d ",_ptr[i]);
  printf("\n");
}
int SeqList::empty()
{
  if(_size == _capacity)
    return 0;
  return 1;
}

int SeqList::binary_search(DateType data)
{
  size_t left = 0;
  size_t right = _size - 1;
  size_t middle = 0;
  if(data > _ptr[right] || data < _ptr[left])
    return -1;
  /*
   * 这里的=号是十分必要的
   */
  while(left <= right)
  {
    middle = (left + right) / 2;
    if(_ptr[middle] > data)
      right = middle - 1;
    else if(_ptr[middle] < data)
      left = middle + 1;
    else
      return middle;
  }
  return -1;
}

int SeqList::binary_search_R(size_t left, size_t right, DateType data)
{
  int pos = -1;
  if(left<=right)
  {
    size_t  middle = (right + left) / 2;
    if(data > _ptr[right] || data < _ptr[left])
      return pos;
    if(_ptr[middle] == data)
      return middle;
    else if(_ptr[middle] > data)
      pos = binary_search_R(left, middle - 1, data);
    else 
    pos = binary_search_R(middle + 1, right, data);
  }
  return pos;
}
