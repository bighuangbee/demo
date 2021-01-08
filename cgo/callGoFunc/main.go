// bar2.go

package main

import "C"
import "fmt"

//export GoExportedFunc
func GoExportedFunc() {
	fmt.Println("I am a GoExportedFunc!")
}