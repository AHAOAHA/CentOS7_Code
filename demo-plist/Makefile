test:test.cpp
	g++ -E test.cpp -o test.i -g
	g++ -S test.i -o test.s -g
	g++ -c test.s -o test.o -g
	g++ test.o -o test -g
.PHONY:clean
clean:
	rm -f test.i test.s test.o test
