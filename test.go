/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"fmt"
	"gopackage/common"
)

import jsoniter "github.com/json-iterator/go"

//5
func f() int {
	i := 5
	defer func() {
		i++
	}()
	return i
}

//1
func f1() (result int) {
	defer func() {
		result++
	}()
	return 0
}

//5
func f2() (r int) {
	t := 5
	defer func() {
		t = t + 5
		fmt.Println("t:", t)
	}()
	return t
}

//1
func f3() (r int) {
	defer func(r int) {
		r = r + 5
	}(r)
	return 1
}

//func main() {
//	//println(f())
//	//println(f1())
//	//println(f2())
//	//println(f3())
//
//	a := []int{1,2,3}
//	for _, v := range a {
//		a = append(a, v)
//	}
//	fmt.Println(a)
//}

func main() {
	type name struct {
		Name string `json:"name"`
		Id int64 `json:"id"`
	}

	n := name{
		Name: "aaa",
		Id:   6673221165400540161,
	}
	j, _ := jsoniter.Marshal(n)
	fmt.Println(string(j))

	fmt.Println(common.Struct2Map(n))
}


