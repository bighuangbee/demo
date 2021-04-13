package main

/*
#cgo LDFLAGS: -L${SRCDIR}/lib -lcallback
#cgo CFLAGS: -I callback
#include "callback.h"

int goCallBackFunc(struct info *, char *);
*/
import "C"
import "fmt"

func main(){
	C.setcallback(C.callbackFuncProto(C.goCallBackFunc))
	C.call()
	C.freeObject()
}

//export goCallBackFunc
func goCallBackFunc(info *C.struct_info, roomId *C.char) C.int{
	fmt.Println("goCallBackTest", info.size, C.GoString(roomId))
	return 1
}