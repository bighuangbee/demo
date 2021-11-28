/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"fmt"
	mqtt "github.com/eclipse/paho.mqtt.golang"
	"time"
)

var MqttClient mqtt.Client

func MqttConn(addr string)error{
	opts := mqtt.NewClientOptions().AddBroker(addr).SetClientID("backend_RTC" + time.Now().Format("20060102150405") )
	opts.SetKeepAlive(60 * time.Second)
	opts.SetPingTimeout(50 * time.Second)
	MqttClient = mqtt.NewClient(opts)
	if token := MqttClient.Connect(); token.Wait() && token.Error() != nil {
		return token.Error()
	}
	return nil
}


func SetMgsHandler(){
	if token := MqttClient.Subscribe("$share/recognition/start/#", 0, func(client mqtt.Client, message mqtt.Message) {
		fmt.Println("【SubRecognizeStart】", string(message.Payload()))


	}); token.Wait() && token.Error() != nil {
		fmt.Println("【SubRecognizeStart】" + token.Error().Error())
	}

}

func main()  {
	MqttConn("tcp://localhost:1883")
	SetMgsHandler()

	for{}
}
