package call

import (
	"fmt"
	"strconv"
	"time"
)

/**
* @Author: bigHuangBee
* @Date: 2020/4/29 12:06
 */

const(
	CALLER_MOINTOR = 1	//指挥中心主叫
	CALLER_DUTY  = 2	//执勤端主叫
	CALLER_UVA = 3		//无人机端主叫

	CALL_ACTION_ACCEPT = 1
	CALL_ACTION_REJECT = 2
	CALL_ACTION_FINISH = 3
	CALL_ACTION_CANCEL = 4
	CALL_ACTION_TIMEOUT = 5

	CALL_STATUS_MONITOR_CALLING = 1		//呼叫成功，正在呼叫指挥中心
	CALL_STATUS_MONITOR_NOT_ONLINE = 2	//呼叫失败，指挥中心不在线
	CALL_STATUS_MONITOR_INCALL = 3		//呼叫失败，指挥中心通话中

	CALL_ACTION_RESULT_FAILED	   	   = 0 //操作失败
	CALL_ACTION_RESULT_ACCEPTED        = 1 //接听成功
	CALL_ACTION_RESULT_ACCEPTED_FAILED = 2 //接听失败
	CALL_ACTION_RESULT_ACCEPTED_BEEN   = 3 //接听失败，已被接听
	CALL_ACTION_RESULT_FINISHED        = 4 //挂断成功
	CALL_ACTION_RESULT_CANCELED        = 5 //

)

var CallAction = map[int]string{
	CALL_ACTION_ACCEPT: "接听通话",
	CALL_ACTION_REJECT: "拒绝通话",
	CALL_ACTION_FINISH: "挂断通话",
	CALL_ACTION_CANCEL: "取消通话",
	CALL_ACTION_TIMEOUT: "呼叫超时",

}
var CallActionResult = map[int]string{
	CALL_ACTION_RESULT_ACCEPTED:        "接听成功",
	CALL_ACTION_RESULT_ACCEPTED_FAILED: "接听失败",
	CALL_ACTION_RESULT_ACCEPTED_BEEN:   "接听失败，当前通话已被接听",
	CALL_ACTION_RESULT_FINISHED:        "挂断成功",
	CALL_ACTION_RESULT_FAILED:          "操作失败，通话已结束或不存在",

}

type CallingLine struct {
	CallFrom   int
	CallTo     int
	CreateTime time.Time
	Timeout    *time.Timer
	Action     chan int
	InCall     bool
	CallId     string
	Caller     int //主叫类型 1=指挥端主叫 2=执勤端主叫
}

var MonitorCallInDispatch = make(chan *CallingLine, 0) //指挥中心通话分发

var CallingQueue = make(map[string]*CallingLine, 0)

func (line *CallingLine)Push(){
	CallingQueue[strconv.Itoa(line.Caller) + strconv.Itoa(line.CallFrom)] = line
}
func (line *CallingLine)Pop(){
	delete(CallingQueue, strconv.Itoa(line.Caller) + strconv.Itoa(line.CallFrom))
}
func (line *CallingLine)Exists() bool{
	_, ok := CallingQueue[strconv.Itoa(line.Caller) + strconv.Itoa(line.CallFrom)]
	if ok{
		return true
	}
	return false
}


func NewCallLine(callFrom int, callTo int, caller int) (*CallingLine){

	callingLine := CallingLine{
		CallFrom:   callFrom,
		CallTo:     callTo,
		CreateTime: time.Now(),
		Timeout:    time.NewTimer(8 * time.Second),
		Caller:     caller,
		CallId:     strconv.Itoa(callFrom),
		Action:     make(chan int, 1),
	}

	fmt.Println("NewCallLine", callingLine)

	callingLine.Push()

	go callingLine.handleCall()

	if caller == CALLER_MOINTOR{

	}else if caller == CALLER_DUTY{
		MonitorCallInDispatch <- &callingLine
	}else if caller == CALLER_UVA{

	}

	//1=呼叫成功 2=呼叫失败，指挥中心不在线 3=呼叫失败，指挥中心正在通话中 4=设备终端用户不在线
	return &callingLine
}

func (calling *CallingLine) handleCall(){
	defer fmt.Println("handleCall ", calling.CallFrom, calling, CallingQueue)
	defer calling.Pop()

	for {
		select {
		case <-calling.Timeout.C:
			fmt.Println("calling timeout :" , calling.CallFrom)
			return
		case action := <- calling.Action:

			calling.Timeout.Stop()

			if action == CALL_ACTION_ACCEPT {
				calling.InCall = true
			}else if action == CALL_ACTION_REJECT{
				return
			}else if action == CALL_ACTION_FINISH{
				return
			}
		}
	}
}