/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: BinTree.h
 * Author: ahaoozhang
 * Date: 2019-09-18 17:09:56 (Wednesday)
 * Describe: 
 *************************************************/
#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <iostream>
#include <stack>
#include <queue>


template <class T>
struct Node {
    Node(T val = T()): _val(val) {}
    Node<T>* _left = nullptr;
    Node<T>* _right = nullptr;
    T _val;
};


namespace AHAOAHA {
    // 二叉树先序遍历
    template <class T>
    void PreOrder(Node<T>* root) {
        Node<T>* cur = root;
        std::stack<Node<T>*> st;

        while(cur != nullptr || !st.empty()) {
            while(cur) {
                std::cout << cur->_val << " ";
                st.push(cur);
                cur = cur->_left;
            }
            if (!st.empty()) {
                cur = st.top();
                st.pop();
                cur = cur->_right;
            }
        }

        std::cout << std::endl;
    }

    //二叉树中序遍历
    template<class T>
    void MidOrder(Node<T>* root) {
        Node<T>* cur = root;
        std::stack<Node<T>*> st;

        while(cur != nullptr || !st.empty()) {
            while(cur) {
                st.push(cur);
                cur = cur->_left;
            }
            if (!st.empty()) {
                cur = st.top();
                st.pop();
                std::cout << cur->_val << " ";

                cur = cur->_right;
            }            
        }

        std::cout << std::endl;
    }

    //后序遍历二叉刷
    template<class T>
    void BakOrder(Node<T>* root) {
        std::stack<Node<T>*> st;
        std::stack<Node<T>*> output;
        Node<T>* cur = root;

        while(cur != nullptr || !st.empty()) {
            while(cur) {
                st.push(cur);
                output.push(cur);

                cur = cur->_right;
            }
            if(!st.empty()) {
                cur = st.top();
                st.pop();
                cur = cur->_left;
            }
        }

        while(!output.empty()) {
            std::cout << output.top()->_val << " ";
            output.pop();
        } 

        std::cout << std::endl;
    }

    //层序遍历
    template <class T>
    void LevelOrder(Node<T>* root) {
        std::queue<Node<T>*> qe;
        Node<T>* cur = root;
        if(cur == nullptr)
            return;
        qe.push(cur);
        while(!qe.empty()) {
            cur = qe.front();
            qe.pop();

            std::cout << cur->_val << " ";

            if (cur->_left)
                qe.push(cur->_left);

            if (cur->_right)
                qe.push(cur->_right);
        }

        std::cout << std::endl;
    }
}


#endif
