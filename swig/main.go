package main

import "C"

import (
	"fmt"
	"swig/swiglib"
)

func main() {
	simpleClass := swiglib.NewSimpleClass()
	result := simpleClass.Hello()
	fmt.Println(result)

	fmt.Println(simpleClass.Say("yyaa"))
}