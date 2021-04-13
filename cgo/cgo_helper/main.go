package main

// char* str = "hello123";
// char str2[] = "hello456";
import "C"
import (
	"fmt"
	"reflect"
	"cgo_helper/helper"
	"unsafe"
)

func main() {

/*
	一、不同Go包中引入的C包之间的类型不能通用，即main包的C.char与cgo_helper包的C.char类型不通用
*/

	helper.PrintCString(C.str)
	//报错信息：cannot use *_Cvar_str (type *_Ctype_char) as type *cgo_helper._Ctype_char

	//方式1：cgo_helper包导出接口，接收Go类型的参数，在cgo_helper包内部再转换为Cgo类型
	helper.PrintGoString("1122")

	//方式2：在当前包创建cgo_helper.CChar类型的对象，再其调用对象的方法
	a := (*helper.CChar)(unsafe.Pointer(&C.str2[0]))
	fmt.Println(a.GoString())

	fmt.Println(C.GoString((&C.str2[0])))

/*
	二、CGO实现可Go和C的互通，但内存模型有差异；C的内存在分配之后就是稳定的，但Go的函数栈是动态伸缩的，即Go访问C的内存是安全，但C访问Go内存可能是不安全的；
	CGo针对向C传入Go内存，会保证在C函数返回前，Go的内存不会发生移动，所以也可以放心使用；
*/

/*
	三、指针转换与运算
		1、底层结构相同的指针，语法层面可以直接强制转换，比如要转换通过type定义的类型；type myInt int32; var m myInt = 1; fmt.Println((int)(m))
		2、Go类型之间转换必须通过类型内置的方法处理，比如:strconv.Atoi()；
		3、Cgo提供C和GO之间字符串/字节的转换函数，C.CString(string) *C.char和C.GoString(*C.char) string，C.CBytes和C.GoBytes
		4、通过unsafe.Pointer操作C指针的转换，任何类型的指针都可以强制转换为unsafe.Pointer类型（中间类型，类似于void *万能指针，可持有任何类型的对象），然后再转换为目标类型
		5、unsafe.Pointer只能持有指针，不能进行指针运算；unsafe.Pointer可以转换为uintptr后进行指针运算；
*/

	// 通过unsafe.Pointer持有转换后的指针
	var p int = 1
	p1 := unsafe.Pointer(&p)
	p2 := (*C.char)(p1)
	fmt.Println("val:",*p2, "type:",reflect.TypeOf(*p2).Name()) //val: 1 type: _Ctype_char

	//go []byte转换为C的底层类型为char的别名类型
	//SrcImgGrayData := (*C.uchar_hi)((unsafe.Pointer)(&in.Data[0]))

	// 通过uintptr对指针进行运算
	//var buf = make([]byte, bufSize)
	//for i := 0; i < int(bufSize); i++ {
	//	p := uintptr(unsafe.Pointer(buf1)) + (uintptr(i) * unsafe.Sizeof(*buf1))
	//	buf = append(buf, *(*byte)(unsafe.Pointer(p)))
	//}

}