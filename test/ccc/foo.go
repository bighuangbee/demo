package main

import "C"
import "fmt"

//export myprint
func myprint(i C.int) {
	fmt.Printf("i = %v\n", uint32(i))
}