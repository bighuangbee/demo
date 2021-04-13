cb:
	mkdir -p lib && rm lib/* -f
	cd callback && g++ -o ../lib/libcallback.so callback.c -fPIC -shared

lib_path = $(shell pwd)
set_env:
	@export LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(lib_path)/lib

run: cb
	make set_env && go run main.go