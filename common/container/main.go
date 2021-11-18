package main

import (
	"container/handler"
	"fmt"
)


type StorageHandler struct {
	handler.IStorage
}


func main(){

	handler.Regester("cos", handler.NewCosClient)
	handler.Regester("oss", handler.NewOssClient)

	storage, _ := handler.CallHandlerFcun("cos", []interface{}{
		&handler.Storage{
			Name:   "11",
			Ak:     "22",
			Sk:     "33",
			Bucket: "44",
			Url:    "55",
		},
	})

	sss := StorageHandler{storage.(*handler.CosStorage)}
	aaa, bbb := sss.GetPicturePreViewURL()


	fmt.Println("----------", aaa, bbb)

	storage1, _ := handler.CallHandlerFcun("oss", []interface{}{
		&handler.Storage{
			Name:   "aa",
			Ak:     "bb",
			Sk:     "cc",
			Bucket: "dd",
			Url:    "ee",
		},
	})

	sss1 := StorageHandler{storage1.(*handler.CosStorage)}
	aaa1, bbb1 := sss1.GetPicturePreViewURL()
	fmt.Println("==========", aaa1, bbb1)

}