package main

import "C"
import (
"fmt"
"unsafe"
)

//export GoExportedFunc
func GoExportedFunc(str *C.char) {
	fmt.Println("go string ",string(C.GoString(str)))
	fmt.Println("I am a GoExportedFunc!--", (*byte)(unsafe.Pointer(str)))
}