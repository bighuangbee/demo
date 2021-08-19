/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"fmt"
	"net"
	"net/rpc"
	"time"
)

type User struct {
	Name string `json:"name"`
}

func (p *User) Test(request string, reply *string) error {
	t1 := time.Now()
	*reply ="test:" + request

	fmt.Println(time.Now().Sub(t1).String())
	return nil
}

func main() {
	rpc.RegisterName("srv.rpc", new(User))

	listener, err := net.Listen("tcp",":1234")
	if err != nil {
		fmt.Println("ListenTCP error", err)
	}

	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("Accept error:", err)
		}
		rpc.ServeConn(conn)
	}
}
