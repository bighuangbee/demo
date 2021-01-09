package main

/*
#include <stdio.h>

extern void GoExportedFunc(char *);

void bar() {
    printf("I am bar--!\n");
	char *foo = "1122d";
	printf("--%s\n", foo);
    GoExportedFunc(foo);
}
*/
import "C"

func main() {

	C.bar()
	//C.bar(C.CString("112"))
}