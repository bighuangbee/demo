package main

import (
	"fmt"
	"gopackage/table"
	"os"
)

func main(){
	t := table.Txlsx{}
	path,_ := os.Getwd()
	fmt.Println(path + "/房地产.xlsx")
	data, err := t.Read(path + "/房地产.xlsx")
	fmt.Println(err, data)
}
