package main

/*
#cgo LDFLAGS: -L${SRCDIR}/lib -lcallback
#cgo CFLAGS: -I callback
#include "callback.h"

int goFuncForCallback(struct info *, char *);
*/
import "C"
import "fmt"

func main(){
	C.setcallback(C.callbackFuncProto(C.goFuncForCallback))
	C.caller()
	C.freeObject()
}

//导出为C函数
//export goFuncForCallback
func goFuncForCallback(info *C.struct_info, roomId *C.char) C.int{
	fmt.Println("goFunc", info.size, C.GoString(roomId))
	return 1
}