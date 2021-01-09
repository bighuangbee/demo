package main

/*
	#include "c.h"
*/
import "C"

import (
	"unsafe"
)

type S struct {
	A int64 // 64bit int
	B int64 // 64bit int
}

func main() {
	s := &S{A: 4, B: 89}
	pass_to_c := (*C.S)(unsafe.Pointer(s))
	C.gostruct(pass_to_c)
}