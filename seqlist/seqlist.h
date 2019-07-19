#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<malloc.h>
typedef int DateType;
class SeqList
{
  public:
    SeqList(size_t capacity = 3);
    SeqList(DateType* array, size_t size);
    void push_back(DateType data);
    void pop_back();
    void push_front(DateType data);
    void pop_front();
    int find(DateType data);
    void insert_pos(size_t pos, DateType data);
    void erase(size_t pos);
    void remove(DateType data);
    void remove_all();
    size_t size();
    int empty();
    void bubble_sort();
    void select_sort();
    /*
     * 优化的选择排序中，有一种特殊情况，那就是当最大的数与最小的数刚好在列表的两边时，如果交换两次，那么就相当于没有交换，这种情况需要特殊处理
     */
    void select_sort_OP();
    int binary_search(DateType data);
    int binary_search_R(size_t left, size_t right, DateType data);
    void print();
    ~SeqList();




  private:
    void swap(DateType& data1, DateType& data2);
    int capacity_increase();
    size_t _capacity;
    size_t _size;
    DateType* _ptr;
};


#endif
