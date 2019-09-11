test:test.c
	g++ -E test.c -o test.i -Wall #预处理
	g++ -S test.i -o test.s -Wall #编译 汇编
	g++ -c test.s -o test.o -Wall #链接
	g++ test.o -o test -Wall      #生成可执行文件
.PHONY:clean
clean:
	rm -f test test.i test.s test.o
