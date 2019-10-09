/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: LevelSum.cpp
 * Author: ahaoozhang
 * Date: 2019-10-09 12:19:57 (星期三)
 * Describe: 
 *************************************************/

#include <vector>
#include <iostream>
using namespace std;

struct Node {
	Node(int val = 0): _val(val)
	{}

	int _val;
	Node* _left = nullptr;
	Node* _right = nullptr;
};

/*
 *       1
 *      / \
 *     3   5
 *    / \   \
 *   6   7   8
 *  计算叶子节点上的值的总和 136 + 137 + 158 = ？
 */

vector<int> v;

void GetTreeNum(Node* root, int num) {
	if (root->_left == nullptr && root->_right == nullptr) {
		v.push_back(num * 10 + root->_val);
		return;
	}
	if (root->_left)
		GetTreeNum(root->_left, num * 10 + root->_val);
	if (root->_right)
		GetTreeNum(root->_right, num * 10 + root->_val);
}

void EchoVector(const vector<int>& v) {
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {
	Node* root = new Node(1);
	root->_left = new Node(3);
	root->_right = new Node(5);
	root->_left->_left = new Node(6);
	root->_left->_right = new Node(7);
	root->_right->_right = new Node(8);
	//tree ready
	
	GetTreeNum(root, 0);
	//EchoVector(v);

	int sum = 0;
	for (auto e : v) {
		sum += e;
	}

	cout << sum << endl;
	return 0;
}