test:
	mkdir -p lib && rm lib/* -f
	g++ -o lib/libtest.so test.c -fPIC -shared

env:
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/mnt/d/server/gopath/github.com/bighuangbee/demo/cgo/libCallback/lib