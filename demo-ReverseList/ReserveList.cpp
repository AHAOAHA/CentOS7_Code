/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: ReserveList.cpp
 * Author: ahaoozhang
 * Date: 2019-09-25 21:00:47 (星期三)
 * Describe: 
 *************************************************/
#include <iostream>


template <class T>
struct Node {
    Node(T val = 0): _val(val), _next(nullptr) 
    {}

    T _val;
    Node<T>* _next;
};

template <class T>
void EchoList(Node<T>* head) {
    while(head) {
        std::cout << head->_val << " ";
        head = head->_next;
    }
    std::cout << std::endl;
}

template <class T>
void _ReserveList(Node<T>* begin, Node<T>* end) {
    Node<T>* first = nullptr;
    Node<T>* second = nullptr;
    Node<T>* third = nullptr;
    
    if(begin == nullptr || begin == end || first->_next == nullptr) {
        return;
    }

    first = begin;
    second = first->_next;
    third = second->_next;

    while(third != end) {
        second->_next = first;
        first = second;
        second = third;
        third = third->_next;
    }
}

template <class T>
void ReserveList(Node<T>* head, int count) {
    //截取链表前count个节点
    Node<T>* cur = head;
    Node<T>* begin = head;
    Node<T>* end = head;

    while(cur) {
        int cut = 0;
        while(cut++ < count) {
            if(end)
                end = end->_next;
            else
                break;
        }
        if (cut != count)
            break;

        //反转begin到end之间的链表[begin, end]
        _ReserveList(begin, end);

        begin = end;
        end = end;

    }
}

int main() {
    Node<int>* head = new Node<int>(1);
    head->_next = new Node<int>(2);
    head->_next->_next = new Node<int>(3);
    head->_next->_next->_next = new Node<int>(4);
    head->_next->_next->_next->_next = new Node<int>(5);

    EchoList(head);

    ReserveList(head, 2);

    EchoList(head);

    return 0;
}