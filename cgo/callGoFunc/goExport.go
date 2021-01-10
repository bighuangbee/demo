package main

import "C"
import (
	"fmt"
	"unsafe"
)

//export GoExportedString
func GoExportedString(str *C.char) {
	fmt.Println("GoExportedString ",string(C.GoString(str)))
}

//export GoExportedInt
func GoExportedInt(p C.int) {
	fmt.Println("GoExportedInt ", int(p))
}

//export GoExportedIntPointer
func GoExportedIntPointer(p *C.int) {
	fmt.Println("GoExportedIntPointer ", (int)(*((*int32)(unsafe.Pointer(p)))))
}