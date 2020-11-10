package Center

import (
	"callDemo/call"
	"callDemo/client"
	"fmt"
	"github.com/bighuangbee/gomod/loger"
	"sync"
	"time"
)

/**
* @Author: bigHuangBee
* @Date: 2020/4/30 10:43
 */

type MonitorCenter struct {
	Client *client.Client
	InCall string	//当前正在通话id，空为空闲
	HandlerLine *call.CallingLine
	Lock *sync.RWMutex
	Notify chan string
}



var Monitors = make(map[int]*MonitorCenter, 0)  //指挥中心端在线账号

func NewMonitor(userId int) (*MonitorCenter){
	monitor := MonitorCenter{
		Notify: make(chan string, 1),
		Lock: new(sync.RWMutex),
		Client:   &client.Client{
			UserId:     userId,
			OpenType:   1,
			OnCalling:  false,
			ConnTime:   time.Now(),
		},
	}

	go func() {
		for {
			select {
				case message := <- monitor.Notify:
					fmt.Println(message)
			}
		}
	}()
	Monitors[userId] = &monitor

	loger.Info("【NewMonitor】", userId, monitor)
	return &monitor
}

func MonitorInCall() (bool) {
	//指挥端同时只能有一个账号在通话
	for _, monitor := range Monitors{
		if monitor.HandlerLine != nil{
			return true
		}
	}
	return false
}

func IsMonitorOnLine() bool{
	if len(Monitors) > 0{
		return true
	}
	return false
}

func CallMonitor(callFrom int) (int, *call.CallingLine) {
	if !IsMonitorOnLine() {
		fmt.Println("指挥中心不在线, callFrom:", callFrom, ", callTo:", ", caller", call.CALLER_DUTY)
		return call.CALL_STATUS_MONITOR_NOT_ONLINE, nil
	}
	if MonitorInCall() {
		fmt.Println("指挥中心正在通话, callFrom:", callFrom, ", callTo:", ", caller", call.CALLER_DUTY)
		return call.CALL_STATUS_MONITOR_INCALL, nil
	}

	line := call.NewCallLine(callFrom, 10086, call.CALLER_DUTY)
	return call.CALL_STATUS_MONITOR_CALLING, line
}

func (monitor *MonitorCenter) SendCallAction(line *call.CallingLine, action int) (actionResult int){
	//	//monitor.Lock.Lock()
	//defer monitor.Lock.Unlock()

	fmt.Println("【发送通话操作】SendCallAction:", action, call.CallAction[action], line)

	if !line.Exists(){
		fmt.Println("【通话操作结果】", call.CALL_ACTION_RESULT_FAILED, call.CallActionResult[call.CALL_ACTION_RESULT_FAILED], line)
		return call.CALL_ACTION_RESULT_FAILED
	}


	if action == call.CALL_ACTION_ACCEPT {
		if line.InCall || monitor.HandlerLine != nil {
			actionResult = call.CALL_ACTION_RESULT_ACCEPTED_BEEN
			fmt.Println("【通话操作结果】", call.CALL_ACTION_RESULT_ACCEPTED_BEEN, call.CallActionResult[call.CALL_ACTION_RESULT_ACCEPTED_BEEN], line)
			return
		}
		monitor.InCall = line.CallId
		monitor.HandlerLine = line

		actionResult = call.CALL_ACTION_RESULT_ACCEPTED
		fmt.Println("【通话操作结果】", call.CALL_ACTION_RESULT_ACCEPTED, call.CallActionResult[call.CALL_ACTION_RESULT_ACCEPTED], line)

	}else if action == call.CALL_ACTION_FINISH && monitor.HandlerLine.CallId == line.CallId && line.InCall{
		monitor.InCall = ""
		monitor.HandlerLine = nil

		actionResult = call.CALL_ACTION_RESULT_FINISHED
		fmt.Println("【通话操作结果】", call.CALL_ACTION_RESULT_FINISHED, call.CallActionResult[call.CALL_ACTION_RESULT_FINISHED], line)
	}else{
		actionResult = call.CALL_ACTION_RESULT_ACCEPTED_FAILED
		fmt.Println("【通话操作结果】", call.CALL_ACTION_RESULT_ACCEPTED_FAILED, call.CallActionResult[call.CALL_ACTION_RESULT_ACCEPTED_FAILED], line)
		return
	}

	line.Action <- action

	return actionResult
}


func monitorCallInScaner(){
	for {
		select {
			case calling := <-call.MonitorCallInDispatch:
				for _, monitor := range Monitors {
					fmt.Println("monitorCallInScaner " , monitor.Client.UserId, calling)
					monitor.Notify <- "terminalCallIn"
				}
				break
		}
	}
}

func SetUp(){
	go monitorCallInScaner()
}