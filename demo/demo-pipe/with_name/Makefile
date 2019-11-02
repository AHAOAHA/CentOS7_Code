.PHONY:all

all:client service

client:./client_src/client.c
	gcc $^ -o $@ -g
service:./service_src/service.c
	gcc $^ -o $@ -g

.PHONY:clean
clean:
	rm -f client service
