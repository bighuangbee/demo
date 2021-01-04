package handler

import (
	"reflect"
)

var StorageMap = make(map[string]interface{}, 0)

func Regester(name string, handlerFcun interface{}){
	StorageMap[name] = handlerFcun
}

func Get(name string)(handlerFcun interface{}, ok bool){
	handlerFcun, ok = StorageMap[name]
	return
}

func CallHandlerFcun(name string, params []interface{}) (obj interface{}, err error){
	in := make([]reflect.Value, 0)
	for _, v := range params{
		in = append(in, reflect.ValueOf(v))
	}

	h, _ := Get(name)
	res := reflect.ValueOf(h).Call(in)

	return res[0].Interface(), nil
}