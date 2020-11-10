package main

import "fmt"

type Person struct {
	Name string
	Age int
}

func (p Person)String()string{
	return "Name: " + p.Name
}

func main(){
	p := Person{Name:"bighuangbee", Age:22}

	fmt.Println(p)
}
