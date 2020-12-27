package main

import (
	"fmt"
	"os"
	"path"
	"strings"
	"time"
)

func fun1(key string) {
	fmt.Printf("fun11 key=%s\n", key)
}

func fun2(key string) {
	fmt.Printf("fun22222222222 key=%s\n", key)
}

var funVar func(key string)
type f func(key string)

var m map[string]f

func main() {

	file, err := os.Open("http://oss.hidrone.cn/hidronedev/Screenshot201224025632.png")
	if err != nil{
		fmt.Println(err)
	}
	fmt.Println(file.Stat())

	t := "20201218105911"
	fmt.Println(t[0:4] + " " + t[4:6] + " " + t[6:8] + " " + t[8:10] + " " + t[10:12] + " " +t[12:14])
	fmt.Println(time.Parse("2006 01 02 15 04 05", t[0:4] + " " + t[4:6] + " " + t[6:8] + " " + t[8:10] + " " + t[10:12] + " " +t[12:14] ))
	fmt.Println(time.Parse("20060102150405", t ))

	a := "2_5651b03fe9900001_8_20201218105911.mp4"
	ext := path.Ext(a)
	b := strings.TrimSuffix(a, ext)
	fmt.Println(b)

	funVar = fun1
	funVar("hello")

	funVar = fun2
	funVar("hello")

	m = make(map[string]f, 0)
	m["1"] = fun1
	ff := m["1"]
	ff("333ggg")
	fmt.Println(ff)


	//t, _ := time.ParseInLocation("2006-01-02 15:04:05", "2020-12-12T19:27:30+08:00", time.Local)
	//fmt.Println(t.UTC().Format("2006-01-02 15:04:05"))
	//
	//t1,_ := time.Parse(time.RFC3339, "2020-12-12T19:27:30+08:00")
	//fmt.Println(t1.UTC().Format("2006-01-02 15:04:05"))
}