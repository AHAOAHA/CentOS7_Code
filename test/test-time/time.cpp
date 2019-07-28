/*************************************************
 * Copyright(C) 2016-2019. All right reserved.
 * 
 * Filename: time.cpp
 * Author: ahaoozhang
 * Date: 2019-07-25 16:06:21 (星期四)
 * Describe: 
 *************************************************/
#include <stdio.h>
#include <time.h>

int main() {
    int t = time(NULL);
    printf("time: %d\n", t);
    return 0;
}
