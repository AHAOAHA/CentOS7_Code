#!/usr/bin/python
#coding:utf-8

def Fib(n):
    first = 1
    second = 1
    if n <= 2:
        return 1
    while n > 2:
        third = second + first
        second = third
        first = second
        n = n - 1
    return third
if __name__ =="__main__":
    print Fib(4)
