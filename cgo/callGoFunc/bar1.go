// bar1.go
package main

/*
#include <stdio.h>

extern void GoExportedFunc();

void bar() {
        printf("I am bar!\n");
        GoExportedFunc();
}
*/
import "C"

func main() {
	C.bar()
}