package main

import "C"

import (
	"fmt"
	"swig/swiglib"
	"unsafe"
)

func main() {
	simpleClass := swiglib.Kdm_CreateMcuSdk()
	fmt.Println(simpleClass)
	initRes := swiglib.Kdm_Init(simpleClass)
	fp := (*bool)(unsafe.Pointer(initRes.Swigcptr()))
	fmt.Println("-------", *fp)

	swiglib.Kdm_SubscriptDeviceStatus(simpleClass, )
}