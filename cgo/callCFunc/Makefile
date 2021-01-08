all:
	mkdir -p build
	gcc -o build/foo.o -c foo.c
	cd build && gcc -shared -Wl,-soname,libfoo.so -o libfoo.so  foo.o
	go build -o build/main main.go

run: all
	export LD_LIBRARY_PATH=$(shell pwd)/build:$LD_LIBRARY_PATH && ./build/main