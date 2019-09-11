#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    char *buf = "hello \\0sorld!";
    int ret = write(1, buf, 1000);


    cout << "ret: " << ret << endl;

    return 0;
}
