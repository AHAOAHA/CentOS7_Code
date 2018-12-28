.PHONY:all
all:client service
cc:g++
client:client.cc
	$(cc) $^ -o $@ -lpthread
client:service.cc
	$(cc) $^ -o $@ -lpthread

.PHONY:clean
clean:
	rm -f client service
