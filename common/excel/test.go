package main

import (
	"fmt"
	"gopackage/table"
	"os"
	"path/filepath"
)

func main(){
	path,_ := os.Getwd()

	t := table.Txlsx{Filename: path + "/房地产.xlsx"}

	filepath.Base(path + "/房地产.xlsx")

	fmt.Println(path + "/房地产.xlsx")
	data, err := t.Read()
	fmt.Println(err, data)
}
