package main

import (
	"fmt"
	"golang.org/x/time/rate"
	"os"
	"os/signal"
	"time"
)

var limit *rate.Limiter

func main(){

	a := uint8(201)
	fmt.Println(a)
	fmt.Println(int32(a))

	r := rate.Every(1* time.Second)
	limit = rate.NewLimiter(r, 10)

	//go test()

	dt, _ := time.ParseInLocation("2006-01-02 15:04:05", "2017-05-11 14:06:06", time.Local)
	fmt.Println(dt.UTC().Format("2006-01-02 15:04:05"))

	//t, _ := time.ParseInLocation("2006-01-02 15:04:05", time.Now().Format("2006-01-02 15:04:05"), time.Local)
	//fmt.Println(t.Format("2006-01-02 15:04:05"))

		// 当天零点
	t := time.Now()
	tm1 := time.Date(t.Year(), t.Month(), t.Day(), 0, 0, 0, 0, t.Location())
	fmt.Println(tm1.Format("2006-01-02 15:04:05"))

	t1, _ := time.ParseInLocation("2006-01-02 15:04:05", tm1.Format("2006-01-02 15:04:05"), time.Local)
	fmt.Println(t1.Format("2006-01-02 15:04:05"))

	t, _ = time.ParseInLocation("2006-01-02 15:04:05", time.Now().Format("2006-01-02 15:04:05"), time.Local)
	fmt.Println(t.UTC().Format("2006-01-02 15:04:05"))

	//formatTimeStr:="2017-04-11 13:33:37"
	//formatTime,err:=time.Parse("2006-01-02 15:04:05",formatTimeStr)
	//if err==nil{
	//	fmt.Println(formatTime.Format("2006-01-02 15:04:05")) //打印结果：2017-04-11 13:33:37 +0000 UTC
	//}

	c := make(chan os.Signal)
	signal.Notify(c, os.Interrupt, os.Kill)
	s := <-c
	fmt.Println("退出信号", s)
}

func test(){
	var count int
	for  {
		if limit.Allow(){
			count += 1
			fmt.Println(count, " ####")
		}else{
			fmt.Println("***")
		}
	}
}
