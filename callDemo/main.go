package main

import (
	"callDemo/Center"
	"callDemo/call"
	"os"
	"os/signal"
	"syscall"
	"time"
)

/**
* @Author: bigHuangBee
* @Date: 2020/4/28 15:31
 */


func init(){
	Center.SetUp()

	Center.NewMonitor(10086)
}

func main(){

	 _, line := Center.CallMonitor(1)


	time.AfterFunc(3 * time.Second, func() {
		 Center.Monitors[10086].SendCallAction(line, call.CALL_ACTION_ACCEPT)
		 //
		 //Center.Monitors[10086].SendCallAction(line, call.CALL_ACTION_ACCEPT)
	})

	time.AfterFunc(4 * time.Second, func() {
		Center.Monitors[10086].SendCallAction(line, call.CALL_ACTION_FINISH)
	})

	time.AfterFunc(5 * time.Second, func() {
		Center.Monitors[10086].SendCallAction(line, call.CALL_ACTION_FINISH)
	})

	done := make(chan os.Signal, 1)
	signal.Notify(done, os.Interrupt, syscall.SIGINT, syscall.SIGTERM)
	<-done
}