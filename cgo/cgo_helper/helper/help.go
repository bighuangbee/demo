package helper

// char* str1 = "hello";
import "C"
import "unsafe"

type CChar C.char

func (p *CChar) GoString() string {
	return C.GoString((*C.char)(p))
}

func PrintCString(cs *C.char) {
	ccc := (*CChar)(cs)
	print(ccc.GoString(), "\n")
}

func PrintGoString(cs string) {
	var aa = []byte(cs)
	ccc := (*C.char)(unsafe.Pointer(&aa[0]))
	PrintCString(ccc)

	bb := C.CString(cs)
	PrintCString(bb)
}
