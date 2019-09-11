.PHONY:all
all:service client

service:./service_src/service.c shared_mem.c
	gcc $^ -o $@ -g
client:./client_src/client.c shared_mem.c
	gcc $^ -o $@ -g

.PHONY:clean
clean:
	rm -f service client

