package main
//#include <stdio.h>
// extern int* goAdd(int, int);
//
// int cAdd(int a, int b) {
//  int *i = goAdd(a, b);
//  return *i;
// }
import "C"
import "fmt"
//export goAdd
func goAdd(a, b C.int) *C.int {
	var c C.int = a + b
	return &c
}
func main() {
	var a, b int = 5, 6
	i := C.cAdd(C.int(a), C.int(b))
	fmt.Println(int(i))
}