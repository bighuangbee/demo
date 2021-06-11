/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package byteCopy

/*
#include <stdlib.h>
*/
import "C"
import (
	"fmt"
	"time"
	"unsafe"
)

//var yuv = make([]byte, 0)

func frameCallBack(buf *C.char, size C.int){
	var yuv = make([]byte, 0)
	yuv = nil
	for i:=0; i<int(size);i++ {
		b := uintptr(unsafe.Pointer(buf)) + (uintptr(i) * unsafe.Sizeof(*buf))
		b1 := *(*byte)(unsafe.Pointer(b))
		yuv = append(yuv, b1)
	}
	time.Sleep(2000*time.Millisecond)

	fmt.Printf("yuv: %v, yuv pointer: %p, buf pointer: %p\n", string(yuv), &yuv, buf)
}

func TestframeCallBack(buf string){
	frameCallBack(C.CString(buf), C.int(len(buf)))
	frameCallBack(C.CString(buf), C.int(len(buf)))
	frameCallBack(C.CString(buf), C.int(len(buf)))
}


