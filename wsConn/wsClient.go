package main

import (
	"fmt"
	"golang.org/x/net/websocket"
	"log"
)

var ws *websocket.Conn

//var origin = "http://175.24.103.55:8080"
//var url = "ws://175.24.103.55:8080/ws"

//var origin = "http://192.1.64.52:8080"
//var url = "ws://192.1.64.52:8080/ws"
//
var origin = "http://52.62.22.150:8080"
var url = "ws://52.62.22.150:8080/ws"

func main() {
	ws, err := websocket.Dial(url, "", origin)
	if err != nil {
		log.Fatal(err)
	}
	message := []byte("ws client test")
	_, err = ws.Write(message)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Send: %s\n", message)

	var msg = make([]byte, 512)
	m, err := ws.Read(msg)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("Receive: %s\n", msg[:m])

	ws.Close()//关闭连接
}