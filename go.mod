module demo

go 1.14

require (
	github.com/JetBlink/dingtalk-notify-go-sdk v0.0.0-20191112085213-0dc836cea13e
	github.com/eclipse/paho.mqtt.golang v1.3.5
	github.com/gorilla/websocket v1.4.2
	github.com/otiai10/gosseract/v2 v2.3.1
	golang.org/x/net v0.0.0-20210510120150-4163338589ed
	gopackage v0.0.0-00010101000000-000000000000
)

replace gopackage => ../code/gopackage
