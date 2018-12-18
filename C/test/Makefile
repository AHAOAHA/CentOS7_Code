test:test.c
	gcc -E test.c -o test.i -Wall #预处理
	gcc -S test.i -o test.s -Wall #编译 汇编
	gcc -c test.s -o test.o -Wall #链接
	gcc test.o -o test -Wall      #生成可执行文件
.PHONY:clean
clean:
	rm -f test test.i test.s test.o
