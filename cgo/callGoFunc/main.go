package main

/*
#include <stdio.h>

extern void GoExportedString(char *);
extern void GoExportedInt(int);
extern void GoExportedIntPointer(int *);

void cFunString(char *str) {
    printf("in cFunString: %s\n", str);
	char *foo = "1122d";
	printf("foo: %s\n", foo);
    GoExportedString(str);
}

void cFunInt(int p) {
    printf("in cFunInt: %d\n", p);
    GoExportedInt(p);
}

int* cFunIntPointer(int *p) {
    printf("in cFunIntPointer: %d\n", *p);
	(*p)++;
    GoExportedIntPointer(p);
	return p;
}

struct CS{
	char *name;
	int age;
	int *balance;
};
void cFunStructPointer(struct CS *p) {
	printf("cFunStructPointer: %s, %d\n", p->name, p->balance);
}
void cFunStruct(struct CS p) {
	printf("cFunStruct: %s\n", p.name);
}
*/
import "C"
import (
	"fmt"
	"unsafe"
)

func main() {
	C.cFunString(C.CString("aabbcc"))

	C.cFunInt(C.int(123))

	var pint = 10
	resPint := C.cFunIntPointer((*C.int)((unsafe.Pointer)(&pint)))
	fmt.Println("cFunIntPointer return:", *resPint)
	fmt.Println(pint)

	//var balance = C.int(100)
	cs := C.struct_CS{
		name: C.CString("weihua"),
		age: 22,
		//balance: &balance,
	}
	C.cFunStructPointer((*C.struct_CS)((unsafe.Pointer)(&cs)))

	C.cFunStruct(cs)
}