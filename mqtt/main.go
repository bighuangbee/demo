package main

import (
	"log"
	"os"
	"time"

	"github.com/eclipse/paho.mqtt.golang"
)


func main() {
	mqtt.DEBUG = log.New(os.Stdout, "", 0)
	mqtt.ERROR = log.New(os.Stdout, "", 0)
	opts := mqtt.NewClientOptions().AddBroker("tcp://175.24.103.55:1883").SetClientID("emqx_test_client1")

	opts.SetKeepAlive(60 * time.Second)
	opts.SetPingTimeout(1 * time.Second)

	c := mqtt.NewClient(opts)
	if token := c.Connect(); token.Wait() && token.Error() != nil {
		panic(token.Error())
	}

	// 发布消息
	token := c.Publish("$queue/hidronetesttopic", 0, false, "##########Hello World")
	token.Wait()


	// 断开连接
	c.Disconnect(250)
	time.Sleep(1 * time.Second)
}