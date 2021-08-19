/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"fmt"
	"net/rpc"
	"time"
)

func main() {
	client, err := rpc.Dial("tcp",":1234")
	if err != nil {
		fmt.Println("dialing", err)
	}

	var reply string

	t1 := time.Now()
	err = client.Call("srv.rpc.Test","hello", &reply)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(time.Now().Sub(t1).String())
	fmt.Println(reply)
}
