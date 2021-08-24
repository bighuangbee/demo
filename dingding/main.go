/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"fmt"
	dingtalk_robot "github.com/JetBlink/dingtalk-notify-go-sdk"
	"io/ioutil"
	"net/http"
)

func dingSend(content string){
	msg := map[string]interface{}{
		"msgtype": "text",
		"text": map[string]string{
			"content": content,
		},
		"at": map[string]interface{}{
			"atMobiles": []string{},
			"isAtAll":   false,
		},
	}

	token := "7e5bf3d1d1e82f04462ed2c47a1b27d3c5ce609e0d91ccbd3ad6044dbf33cf9c"
	secret := "SEC2e4ec55ab3ef7a54db44bc99089bf8ac49b65fc56bf21c4b3672206c4728307b"
	robot := dingtalk_robot.NewRobot(token, secret)
	if err := robot.SendMessage(msg); err != nil {
		fmt.Println(err)
	}
}

func main()  {
	http.HandleFunc("/watch", func(w http.ResponseWriter, r *http.Request) {
		msg, _ := ioutil.ReadAll(r.Body)

		fmt.Println(string(msg))
		dingSend(string(msg))
	})

	http.ListenAndServe("0.0.0.0:8888", nil)
}
