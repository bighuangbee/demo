package main

/*
#include <stdio.h>
void plusOne(int *i) {
    (*i)++;
}
*/
import "C"
import (
	"fmt"
	"unsafe"
)

func main() {
	s1 := make([]int, 5)
	//var a int = 5
	//s1[1] = &a
	C.plusOne((*C.int)((unsafe.Pointer)(&s1[0])))
	fmt.Println(s1[0])
}