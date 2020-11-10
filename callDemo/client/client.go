package client

import (
	"strconv"
	"time"
)

var connTimeout = 60 * time.Second

type Client struct {
	UserId     int
	OpenType   int    //open_type 1=指挥中心 2=执勤端 3=无人机
	OnCalling  bool   //当前是否在通话
	Pos        Pos    //坐标
	Num        string //编号
	Name       string //名称
	DeviceUuid string //设备唯一码
	TaskId     int64
	TaskName   string
	HandleId   int
	ConnTime   time.Time
	VodRecord	int	//是否启用录制
}

const OPEN_TYPE_MOINTOR = 1
const OPEN_TYPE_TERMINAL  = 2
const OPEN_TYPE_UVA = 3

const(
	PERSONAL_ADD        = 101	//上线
	PERSONAL_UPDATE_POS = 102	//位置更新
	PERSONAL_DEL        = 201	//下线
)

const messageType = 1

var monitorOnCallId = "" //指挥中心当前正在通话的id

type MessageData struct {
	CallId 	string `json:"call_id, omitempty"`
	Msg 	string `json:"msg, omitempty"`
	UserId	int `json:"user_id, omitempty"`
	Nickname	string `json:"nickname, omitempty"`
	CreateTiime	string `json:"create_time, omitempty"`
}
type Respone struct {		//回复客户端的消息体
	Message string `json:"message"`
	Result 	string `json:"result, omitempty"`
	Data 	MessageData `json:"data, omitempty"`
}

type Transfer struct {		//向其他连接发送的消息体
	Message string 		`json:"message"`
	Data 	MessageData `json:"data, omitempty"`
}

type Data struct {
	UserId int 		`json:"user_id,omitempty"`
	CallId string 	`json:"call_id,omitempty"`
}
type Pos struct {
	Lng float64 `json:"lng"`
	Lat float64 `json:"lat"`
}
type messageBody struct {		//接收客户端发送的消息体
	Message string 	`json:"message,omitempty"`
	Result 	string 	`json:"result,omitempty"`
	Data 	Data 	`json:"data,omitempty"`
	Pos 	Pos		`json:"pos"`
}

type ClientInterface interface {
	heartbeat()
	messageHandler()
}

/*
	@param user_id 发起呼叫的user_id
*/
func createCallId(open_type, user_id int) string {
	return strconv.Itoa(open_type) + strconv.Itoa(user_id) + strconv.FormatInt(time.Now().Unix(), 10)
}

func GetClientKey(open_type, user_id int) string {
	return strconv.Itoa(open_type) + "_" + strconv.Itoa(user_id)
}

func PosFilter(pos Pos) bool{
	if(pos.Lat < 0.000001 || pos.Lng < 0.000001) {
		return false
	}
	return true
}