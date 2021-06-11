package main

import (
	"fmt"
	mqtt "github.com/eclipse/paho.mqtt.golang"
	"io"
	"io/ioutil"
	"net/http"
	"time"
)

//const addr = "tcp://175.24.103.55:1883"
const addr = "tcp://localhost:1883"

func mqttTest(){
	opts := mqtt.NewClientOptions().AddBroker(addr).SetClientID("emqx_test_client1")

	opts.SetKeepAlive(60 * time.Second)
	opts.SetPingTimeout(1 * time.Second)

	c := mqtt.NewClient(opts)
	if token := c.Connect(); token.Wait() && token.Error() != nil {
		panic(token.Error())
	}

	// 发布消息
	token := c.Publish("$queue/hidronetesttopic", 0, false, "##########Hello World")
	token.Wait()
}

func main() {


	http.HandleFunc("/", IndexHandler)
	http.ListenAndServe(":8000", nil)
}

func IndexHandler(w http.ResponseWriter, r *http.Request){

	//读取请求体信息
	bodyContent, err := ioutil.ReadAll(r.Body)
	if err != nil && err != io.EOF {
		fmt.Printf("read body content failed, err:[%s]\n", err.Error())
		return
	}
	fmt.Printf("%s\n", string(bodyContent))
}