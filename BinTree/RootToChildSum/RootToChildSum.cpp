/********************************************************************
 * Copyright(C) 2016-2020. All right reserved.
 * 
 * Filename: RootToChildSum.cpp
 * Author: ahaoozhang
 * Date: 2020-01-12 16:19:27 (Sunday)
 * Describe: 计算二叉树从根路径出发到各个叶子节点组成数组的和(0 <= data <= 9)
 *            1
 *           / \
 *          3   5
 *         / \   \
 *        7   8   9
 * 
 *       137+138+159=?
 ********************************************************************/
#include <iostream>
#include <vector>
#include <cassert>

struct Node {
    Node(uint64_t data = uint16_t()): _data(data) 
    {}

    Node* _left = nullptr;
    Node* _right = nullptr;
    uint64_t _data;
};

static void _EchoVector(std::vector<uint64_t> &v) {
    for (auto e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

static void _RecordTreeNum(std::vector<uint64_t>& v, Node* root, uint64_t pre) {
    if (!root) {
        // 防止root为空
        assert(0);
    }
    pre = pre * 10 + root->_data;
    if (root->_left) {
        _RecordTreeNum(v, root->_left, pre);
    }
    if (root->_right) {
        _RecordTreeNum(v, root->_right, pre);
    }
    if (!root->_left && !root->_right) {
        v.push_back(pre);
    }
}

uint64_t GetRootToChildSum(Node* root) {
    std::vector<uint64_t> v;
    _RecordTreeNum(v, root, 0);
    //_EchoVector(v);   // debug
    uint64_t sum = 0;
    for (auto& e : v) {
        sum += e;
    }
    return sum;
}


int main() {
    // create tree
    Node* root = new Node(uint64_t(1));
    root->_left = new Node(uint64_t(3));
    root->_right = new Node(uint64_t(5));
    root->_left->_left = new Node(uint64_t(7));
    root->_left->_right = new Node(uint64_t(8));
    root->_right->_right = new Node(uint64_t(9));
    // 

    std::cout << "sum: " << GetRootToChildSum(root) << std::endl;
    return 0;
}
