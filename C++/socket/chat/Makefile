.PHONY:all
all:service
service:main.cc
	g++ $^ -o $@ -lpthread
.PHONY:clean
clean:
	rm -f service
