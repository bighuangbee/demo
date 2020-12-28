/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.1
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

// source: swiglib.i

package swiglib

/*
#define intgo swig_intgo
typedef void *swig_voidp;

#include <stdint.h>


typedef long long intgo;
typedef unsigned long long uintgo;



typedef struct { char *p; intgo n; } _gostring_;
typedef struct { void* array; intgo len; intgo cap; } _goslice_;


typedef long long swig_type_1;
typedef long long swig_type_2;
typedef long long swig_type_3;
typedef long long swig_type_4;
typedef _gostring_ swig_type_5;
typedef _gostring_ swig_type_6;
typedef _gostring_ swig_type_7;
typedef long long swig_type_8;
typedef long long swig_type_9;
typedef long long swig_type_10;
typedef long long swig_type_11;
typedef _gostring_ swig_type_12;
typedef _gostring_ swig_type_13;
typedef _gostring_ swig_type_14;
extern void _wrap_Swig_free_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
extern uintptr_t _wrap_Swig_malloc_swiglib_6d4e22488d3f2f59(swig_intgo arg1);
extern uintptr_t _wrap_new_StringVector__SWIG_0_swiglib_6d4e22488d3f2f59(void);
extern uintptr_t _wrap_new_StringVector__SWIG_1_swiglib_6d4e22488d3f2f59(swig_type_1 arg1);
extern uintptr_t _wrap_new_StringVector__SWIG_2_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
extern swig_type_2 _wrap_StringVector_size_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
extern swig_type_3 _wrap_StringVector_capacity_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
extern void _wrap_StringVector_reserve_swiglib_6d4e22488d3f2f59(uintptr_t arg1, swig_type_4 arg2);
extern _Bool _wrap_StringVector_isEmpty_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
extern void _wrap_StringVector_clear_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
extern void _wrap_StringVector_add_swiglib_6d4e22488d3f2f59(uintptr_t arg1, swig_type_5 arg2);
extern swig_type_6 _wrap_StringVector_get_swiglib_6d4e22488d3f2f59(uintptr_t arg1, swig_intgo arg2);
extern void _wrap_StringVector_set_swiglib_6d4e22488d3f2f59(uintptr_t arg1, swig_intgo arg2, swig_type_7 arg3);
extern void _wrap_delete_StringVector_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
extern uintptr_t _wrap_new_ByteVector__SWIG_0_swiglib_6d4e22488d3f2f59(void);
extern uintptr_t _wrap_new_ByteVector__SWIG_1_swiglib_6d4e22488d3f2f59(swig_type_8 arg1);
extern uintptr_t _wrap_new_ByteVector__SWIG_2_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
extern swig_type_9 _wrap_ByteVector_size_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
extern swig_type_10 _wrap_ByteVector_capacity_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
extern void _wrap_ByteVector_reserve_swiglib_6d4e22488d3f2f59(uintptr_t arg1, swig_type_11 arg2);
extern _Bool _wrap_ByteVector_isEmpty_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
extern void _wrap_ByteVector_clear_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
extern void _wrap_ByteVector_add_swiglib_6d4e22488d3f2f59(uintptr_t arg1, char arg2);
extern char _wrap_ByteVector_get_swiglib_6d4e22488d3f2f59(uintptr_t arg1, swig_intgo arg2);
extern void _wrap_ByteVector_set_swiglib_6d4e22488d3f2f59(uintptr_t arg1, swig_intgo arg2, char arg3);
extern void _wrap_delete_ByteVector_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
extern uintptr_t _wrap_new_SimpleClass_swiglib_6d4e22488d3f2f59(void);
extern swig_type_12 _wrap_SimpleClass_hello_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
extern swig_type_13 _wrap_SimpleClass_say_swiglib_6d4e22488d3f2f59(uintptr_t arg1, swig_type_14 arg2);
extern void _wrap_delete_SimpleClass_swiglib_6d4e22488d3f2f59(uintptr_t arg1);
#undef intgo
#cgo LDFLAGS: -L/mnt/d/server/www/demo/swig -lsimple
*/
import "C"

import "unsafe"
import _ "runtime/cgo"
import "sync"


type _ unsafe.Pointer



var Swig_escape_always_false bool
var Swig_escape_val interface{}


type _swig_fnptr *byte
type _swig_memberptr *byte


type _ sync.Mutex


type swig_gostring struct { p uintptr; n int }
func swigCopyString(s string) string {
  p := *(*swig_gostring)(unsafe.Pointer(&s))
  r := string((*[0x7fffffff]byte)(unsafe.Pointer(p.p))[:p.n])
  Swig_free(p.p)
  return r
}

func Swig_free(arg1 uintptr) {
	_swig_i_0 := arg1
	C._wrap_Swig_free_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0))
}

func Swig_malloc(arg1 int) (_swig_ret uintptr) {
	var swig_r uintptr
	_swig_i_0 := arg1
	swig_r = (uintptr)(C._wrap_Swig_malloc_swiglib_6d4e22488d3f2f59(C.swig_intgo(_swig_i_0)))
	return swig_r
}

type SwigcptrStringVector uintptr

func (p SwigcptrStringVector) Swigcptr() uintptr {
	return (uintptr)(p)
}

func (p SwigcptrStringVector) SwigIsStringVector() {
}

func NewStringVector__SWIG_0() (_swig_ret StringVector) {
	var swig_r StringVector
	swig_r = (StringVector)(SwigcptrStringVector(C._wrap_new_StringVector__SWIG_0_swiglib_6d4e22488d3f2f59()))
	return swig_r
}

func NewStringVector__SWIG_1(arg1 int64) (_swig_ret StringVector) {
	var swig_r StringVector
	_swig_i_0 := arg1
	swig_r = (StringVector)(SwigcptrStringVector(C._wrap_new_StringVector__SWIG_1_swiglib_6d4e22488d3f2f59(C.swig_type_1(_swig_i_0))))
	return swig_r
}

func NewStringVector__SWIG_2(arg1 StringVector) (_swig_ret StringVector) {
	var swig_r StringVector
	_swig_i_0 := arg1.Swigcptr()
	swig_r = (StringVector)(SwigcptrStringVector(C._wrap_new_StringVector__SWIG_2_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0))))
	return swig_r
}

func NewStringVector(a ...interface{}) StringVector {
	argc := len(a)
	if argc == 0 {
		return NewStringVector__SWIG_0()
	}
	if argc == 1 {
		if _, ok := a[0].(int64); !ok {
			goto check_2
		}
		return NewStringVector__SWIG_1(a[0].(int64))
	}
check_2:
	if argc == 1 {
		return NewStringVector__SWIG_2(a[0].(StringVector))
	}
	panic("No match for overloaded function call")
}

func (arg1 SwigcptrStringVector) Size() (_swig_ret int64) {
	var swig_r int64
	_swig_i_0 := arg1
	swig_r = (int64)(C._wrap_StringVector_size_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0)))
	return swig_r
}

func (arg1 SwigcptrStringVector) Capacity() (_swig_ret int64) {
	var swig_r int64
	_swig_i_0 := arg1
	swig_r = (int64)(C._wrap_StringVector_capacity_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0)))
	return swig_r
}

func (arg1 SwigcptrStringVector) Reserve(arg2 int64) {
	_swig_i_0 := arg1
	_swig_i_1 := arg2
	C._wrap_StringVector_reserve_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0), C.swig_type_4(_swig_i_1))
}

func (arg1 SwigcptrStringVector) IsEmpty() (_swig_ret bool) {
	var swig_r bool
	_swig_i_0 := arg1
	swig_r = (bool)(C._wrap_StringVector_isEmpty_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0)))
	return swig_r
}

func (arg1 SwigcptrStringVector) Clear() {
	_swig_i_0 := arg1
	C._wrap_StringVector_clear_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0))
}

func (arg1 SwigcptrStringVector) Add(arg2 string) {
	_swig_i_0 := arg1
	_swig_i_1 := arg2
	C._wrap_StringVector_add_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0), *(*C.swig_type_5)(unsafe.Pointer(&_swig_i_1)))
	if Swig_escape_always_false {
		Swig_escape_val = arg2
	}
}

func (arg1 SwigcptrStringVector) Get(arg2 int) (_swig_ret string) {
	var swig_r string
	_swig_i_0 := arg1
	_swig_i_1 := arg2
	swig_r_p := C._wrap_StringVector_get_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0), C.swig_intgo(_swig_i_1))
	swig_r = *(*string)(unsafe.Pointer(&swig_r_p))
	var swig_r_1 string
 swig_r_1 = swigCopyString(swig_r) 
	return swig_r_1
}

func (arg1 SwigcptrStringVector) Set(arg2 int, arg3 string) {
	_swig_i_0 := arg1
	_swig_i_1 := arg2
	_swig_i_2 := arg3
	C._wrap_StringVector_set_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0), C.swig_intgo(_swig_i_1), *(*C.swig_type_7)(unsafe.Pointer(&_swig_i_2)))
	if Swig_escape_always_false {
		Swig_escape_val = arg3
	}
}

func DeleteStringVector(arg1 StringVector) {
	_swig_i_0 := arg1.Swigcptr()
	C._wrap_delete_StringVector_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0))
}

type StringVector interface {
	Swigcptr() uintptr
	SwigIsStringVector()
	Size() (_swig_ret int64)
	Capacity() (_swig_ret int64)
	Reserve(arg2 int64)
	IsEmpty() (_swig_ret bool)
	Clear()
	Add(arg2 string)
	Get(arg2 int) (_swig_ret string)
	Set(arg2 int, arg3 string)
}

type SwigcptrByteVector uintptr

func (p SwigcptrByteVector) Swigcptr() uintptr {
	return (uintptr)(p)
}

func (p SwigcptrByteVector) SwigIsByteVector() {
}

func NewByteVector__SWIG_0() (_swig_ret ByteVector) {
	var swig_r ByteVector
	swig_r = (ByteVector)(SwigcptrByteVector(C._wrap_new_ByteVector__SWIG_0_swiglib_6d4e22488d3f2f59()))
	return swig_r
}

func NewByteVector__SWIG_1(arg1 int64) (_swig_ret ByteVector) {
	var swig_r ByteVector
	_swig_i_0 := arg1
	swig_r = (ByteVector)(SwigcptrByteVector(C._wrap_new_ByteVector__SWIG_1_swiglib_6d4e22488d3f2f59(C.swig_type_8(_swig_i_0))))
	return swig_r
}

func NewByteVector__SWIG_2(arg1 ByteVector) (_swig_ret ByteVector) {
	var swig_r ByteVector
	_swig_i_0 := arg1.Swigcptr()
	swig_r = (ByteVector)(SwigcptrByteVector(C._wrap_new_ByteVector__SWIG_2_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0))))
	return swig_r
}

func NewByteVector(a ...interface{}) ByteVector {
	argc := len(a)
	if argc == 0 {
		return NewByteVector__SWIG_0()
	}
	if argc == 1 {
		if _, ok := a[0].(int64); !ok {
			goto check_2
		}
		return NewByteVector__SWIG_1(a[0].(int64))
	}
check_2:
	if argc == 1 {
		return NewByteVector__SWIG_2(a[0].(ByteVector))
	}
	panic("No match for overloaded function call")
}

func (arg1 SwigcptrByteVector) Size() (_swig_ret int64) {
	var swig_r int64
	_swig_i_0 := arg1
	swig_r = (int64)(C._wrap_ByteVector_size_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0)))
	return swig_r
}

func (arg1 SwigcptrByteVector) Capacity() (_swig_ret int64) {
	var swig_r int64
	_swig_i_0 := arg1
	swig_r = (int64)(C._wrap_ByteVector_capacity_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0)))
	return swig_r
}

func (arg1 SwigcptrByteVector) Reserve(arg2 int64) {
	_swig_i_0 := arg1
	_swig_i_1 := arg2
	C._wrap_ByteVector_reserve_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0), C.swig_type_11(_swig_i_1))
}

func (arg1 SwigcptrByteVector) IsEmpty() (_swig_ret bool) {
	var swig_r bool
	_swig_i_0 := arg1
	swig_r = (bool)(C._wrap_ByteVector_isEmpty_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0)))
	return swig_r
}

func (arg1 SwigcptrByteVector) Clear() {
	_swig_i_0 := arg1
	C._wrap_ByteVector_clear_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0))
}

func (arg1 SwigcptrByteVector) Add(arg2 byte) {
	_swig_i_0 := arg1
	_swig_i_1 := arg2
	C._wrap_ByteVector_add_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0), C.char(_swig_i_1))
}

func (arg1 SwigcptrByteVector) Get(arg2 int) (_swig_ret byte) {
	var swig_r byte
	_swig_i_0 := arg1
	_swig_i_1 := arg2
	swig_r = (byte)(C._wrap_ByteVector_get_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0), C.swig_intgo(_swig_i_1)))
	return swig_r
}

func (arg1 SwigcptrByteVector) Set(arg2 int, arg3 byte) {
	_swig_i_0 := arg1
	_swig_i_1 := arg2
	_swig_i_2 := arg3
	C._wrap_ByteVector_set_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0), C.swig_intgo(_swig_i_1), C.char(_swig_i_2))
}

func DeleteByteVector(arg1 ByteVector) {
	_swig_i_0 := arg1.Swigcptr()
	C._wrap_delete_ByteVector_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0))
}

type ByteVector interface {
	Swigcptr() uintptr
	SwigIsByteVector()
	Size() (_swig_ret int64)
	Capacity() (_swig_ret int64)
	Reserve(arg2 int64)
	IsEmpty() (_swig_ret bool)
	Clear()
	Add(arg2 byte)
	Get(arg2 int) (_swig_ret byte)
	Set(arg2 int, arg3 byte)
}

type SwigcptrSimpleClass uintptr

func (p SwigcptrSimpleClass) Swigcptr() uintptr {
	return (uintptr)(p)
}

func (p SwigcptrSimpleClass) SwigIsSimpleClass() {
}

func NewSimpleClass() (_swig_ret SimpleClass) {
	var swig_r SimpleClass
	swig_r = (SimpleClass)(SwigcptrSimpleClass(C._wrap_new_SimpleClass_swiglib_6d4e22488d3f2f59()))
	return swig_r
}

func (arg1 SwigcptrSimpleClass) Hello() (_swig_ret string) {
	var swig_r string
	_swig_i_0 := arg1
	swig_r_p := C._wrap_SimpleClass_hello_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0))
	swig_r = *(*string)(unsafe.Pointer(&swig_r_p))
	var swig_r_1 string
 swig_r_1 = swigCopyString(swig_r) 
	return swig_r_1
}

func (arg1 SwigcptrSimpleClass) Say(arg2 string) (_swig_ret string) {
	var swig_r string
	_swig_i_0 := arg1
	_swig_i_1 := arg2
	swig_r_p := C._wrap_SimpleClass_say_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0), *(*C.swig_type_14)(unsafe.Pointer(&_swig_i_1)))
	swig_r = *(*string)(unsafe.Pointer(&swig_r_p))
	if Swig_escape_always_false {
		Swig_escape_val = arg2
	}
	var swig_r_1 string
 swig_r_1 = swigCopyString(swig_r) 
	return swig_r_1
}

func DeleteSimpleClass(arg1 SimpleClass) {
	_swig_i_0 := arg1.Swigcptr()
	C._wrap_delete_SimpleClass_swiglib_6d4e22488d3f2f59(C.uintptr_t(_swig_i_0))
}

type SimpleClass interface {
	Swigcptr() uintptr
	SwigIsSimpleClass()
	Hello() (_swig_ret string)
	Say(arg2 string) (_swig_ret string)
}


