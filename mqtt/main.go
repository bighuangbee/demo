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
	opts := mqtt.NewClientOptions().AddBroker(addr).SetClientID("1_1231").SetUsername("go 12").SetPassword("eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VybmFtZSI6IjEzNzE5NDkwMDAxIiwibmlja25hbWUiOiLnjovlsI_omY4wMDAxIiwidXNlclR5cGUiOjEsImNvbXBhbnlfaWQiOjEsInJvbGVzIjpbImFkbWluIl0sImRldmljZV91dWlkIjoiIiwiZXhwIjoxNjI4MTY3MTI2LCJqdGkiOiIzIiwiaXNzIjoiaGlkcm9uZS5zcnYuc3lzdWVyIn0.Pmyr8i20evmDtnitrymSfAR-YyUsELvYLHXVNwL1VPQ")

	opts.SetKeepAlive(60 * time.Second)
	opts.SetPingTimeout(10 * time.Second)


	c := mqtt.NewClient(opts)
	if token := c.Connect(); token.Wait() && token.Error() != nil {
		fmt.Println(token.Error())
		panic(token.Error())
	}

	c.Subscribe("testtopic/#", 0, func(client mqtt.Client, message mqtt.Message) {
		fmt.Println("===="+string(message.Payload()))
	})
	// 发布消息
	token := c.Publish("$queue/hidronetesttopic", 0, false, "##########Hello World")

	time.AfterFunc(5*time.Second, func() {
		// 发布消息
		token1 := c.Publish("$queue/hidronetesttopic", 0, false, "##########Hello World")
		ret := token1.Wait()
		fmt.Println("ret1:", ret, "IsConnected:", c.IsConnected())
	})
	ret := token.Wait()
	fmt.Println("ret:", ret)
}

func main() {
	go mqttTest()

	for{}

	//http.HandleFunc("/", IndexHandler)
	//http.ListenAndServe(":8000", nil)
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
