.PHONY:all
all:client service
cc:g++
client:client.cc
	$(cc) $^ -o $@
client:service.cc
	$(cc) $^ -o $@

.PHONY:clean
clean:
	rm -f client service
