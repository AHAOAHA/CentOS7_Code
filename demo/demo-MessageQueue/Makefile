.PHONY:all
all:service client

service:./service_src/service.c message.c
	gcc $^ -o $@ -g
client:./client_src/client.c message.c
	gcc $^ -o $@ -g

.PHONY:clean
clean:
	rm -f service client
