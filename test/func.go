package main

import "fmt"

func decortor(fn func(string))func (string){
	return func(s string) {
		fmt.Println("--decortor", 1)
		fn(s)
		fmt.Println("--decortor")
	}
}

func main() {

	decortor(func(s string) {
		fmt.Println(s)
	})("123")

}