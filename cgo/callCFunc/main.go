package main
// #cgo LDFLAGS: -L ./build -lfoo
// #cgo CFLAGS: -I ./
// #include "foo.h"
import "C"
import "fmt"

func main() {
	fmt.Println(C.count)
	C.foo()
}