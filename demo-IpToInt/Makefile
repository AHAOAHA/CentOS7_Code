.PHONY:all
all:IntToIp IpToInt
IntToIp:IntToIp.cpp
	g++ $^ -o $@
IpToInt:IpToInt.cpp
	g++ $^ -o $@

.PHONY:clean
clean:
	rm -r IntToIp IpToInt
