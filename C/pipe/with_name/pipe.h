/*
 * 当管道中有数据可读时：
 *                    此时写端关闭，read函数继续读取数据；读完数据即返回0，若返回0read接口不会更改原本用来存放read数据的内存中的内容。
 *                    此时写端未关闭，read函数也会依然读取数据，读完数据即堵塞。
 * 当管道中没有数据时：
 *                    此时写端没有关闭，read接口huiduse
 *                    此时写端已经关闭，read接口返回0
 * 
 * 创建管道文件不支持当前用户主文件夹 '~'
 * 
 * 
 */


#ifndef _PIPE_H_
#define _PIPE_H_


#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


#endif
