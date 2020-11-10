package main

import (
	"callDemo/callLine"
	"os"
	"os/signal"
	"syscall"
)

/**
* @Author: bigHuangBee
* @Date: 2020/4/28 15:31
 */




func main(){
	call.NewCallLine(1, 10086, call.CALLER_DUTY)


	done := make(chan os.Signal, 1)
	signal.Notify(done, os.Interrupt, syscall.SIGINT, syscall.SIGTERM)
	<-done
}