all:
	mkdir build -p
	g++ -o build/cplus.o -c cplus.cpp
	g++ -o build/c.o -c c.c
	cd build && ar r libcgo_test.so c.o cplus.o
	go build -o build/main main.go