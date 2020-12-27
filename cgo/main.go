package main

// #cgo LDFLAGS: -L . -lcgo_test -lstdc++
// #cgo CFLAGS: -I ./
// #include "c.h"
import "C"

func main() {
	C.sayHello()
}