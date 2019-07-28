/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: test.cpp
 * Author: ahaoozhang
 * Date: 2019-07-23 10:52:38 (星期二)
 * Describe: 
 *************************************************/
#include <stdio.h>
#include <iostream>

void test(int 1, void* arg) {
	std::cout << arg << std::endl;
}
int main() {
	test(1, _1);
	return 0;
}
