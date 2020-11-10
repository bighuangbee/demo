package main

import (
	"flag"
	"github.com/gorilla/websocket"
	"log"
	"net"
	"net/http"
)


var addr = flag.String("addr", "0.0.0.0:8080", "http service address")

var upgrader = websocket.Upgrader{}

func handler(w http.ResponseWriter, r *http.Request) {
	c, err := upgrader.Upgrade(w, r, nil)
	if err != nil {
		log.Print("upgrade:", err)
		return
	}
	defer c.Close()
	for {
		mt, message, err := c.ReadMessage()
		if err != nil {
			log.Println("read:", err)
			break
		}
		log.Printf("recv: %s", message)
		err = c.WriteMessage(mt, append([]byte("server respone: "), message...))
		if err != nil {
			log.Println("write:", err)
			break
		}
	}
}


func main() {
	flag.Parse()
	log.SetFlags(0)
	http.HandleFunc("/ws", handler)
	log.Fatal(http.ListenAndServe(*addr, nil))
}


func RemoteIp(req *http.Request) string {
	remoteAddr := req.RemoteAddr
	if ip := exnet.ClientPublicIP(req); ip != "" {
		remoteAddr = ip
	} else if ip := exnet.ClientIP(req); ip != "" {
		remoteAddr = ip
	} else if ip := req.Header.Get("X-Real-IP"); ip != "" {
		remoteAddr = ip
	} else if ip = req.Header.Get("X-Forwarded-For"); ip != "" {
		remoteAddr = ip
	} else {
		remoteAddr, _, _ = net.SplitHostPort(remoteAddr)
	}

	if remoteAddr == "::1" {
		remoteAddr = "127.0.0.1"
	}

	return remoteAddr
}