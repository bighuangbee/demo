package main

/*
extern void myprint(int i);

void dofoo(void) {
    int i;
    for (i=0;i<10;i++) {
        myprint(i);
    }
}
*/
import "C"

func main() {
	C.dofoo()
}