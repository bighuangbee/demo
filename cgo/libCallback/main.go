package main

/*
#cgo LDFLAGS: -L ./lib -ltest
#cgo CFLAGS: -I./
#include "test.h"

int goCallBackTest(struct info *, char *);
*/
import "C"
import "fmt"

func main(){
	C.setcallback(C.callbackFuncProto(C.goCallBackTest))
	C.call()
	C.clean()
}

//export goCallBackTest
func goCallBackTest(info *C.struct_info, roomId *C.char) C.int{
	fmt.Println("goCallBackTest", info.size, C.GoString(roomId))
	return 1
}