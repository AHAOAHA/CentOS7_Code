.PHONY:all
all:service client
service:service.c
	gcc $^ -o $@ -lpthread
client:client.c
	gcc $^ -o $@ -lpthread
.PHONY:clean
clean:
	rm -f service client
