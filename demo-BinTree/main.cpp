/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: main.cpp
 * Author: ahaoozhang
 * Date: 2019-09-18 17:12:25 (Wednesday)
 * Describe: 
 *************************************************/
#include "BinTree.h"

/*
 *         1
 *        / \
 *       3   6
 *      / \
 *     2   5
 */

int main() {
    Node<int>* head = new Node<int>(1);
    head->_left = new Node<int>(3);
    head->_right = new Node<int>(6);
    head->_left->_left = new Node<int>(2);
    head->_left->_right = new Node<int>(5);

    AHAOAHA::PreOrder(head); // 前序遍历
    AHAOAHA::MidOrder(head);
    return 0;
}
