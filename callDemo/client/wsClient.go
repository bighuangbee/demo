package client

/**
* @Author: bigHuangBee
* @Date: 2020/4/30 16:55
 */


type WsClient struct {
	Conn    int
	*Client
}

var Clients = make(map[int]*WsClient, 0)
