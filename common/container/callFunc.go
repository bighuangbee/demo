package main

import (
	"fmt"
	"reflect"
)

func GeURL(s string, a int)(url string, err error){
	fmt.Println("GetPicturePreViewURL", s)
	url += s
	return s, nil
}

var fMap = map[string]interface{}{
	"GeURL": GeURL,
}

func main(){
	geURL := fMap["GeURL"]
	geURLObj := reflect.ValueOf(geURL)
	fmt.Println(geURLObj.Type())

	in := make([]reflect.Value, 0)
	in = append(in, reflect.ValueOf("abcc"))
	in = append(in, reflect.ValueOf(124))
	res := geURLObj.Call(in)

	fmt.Println(res)
}