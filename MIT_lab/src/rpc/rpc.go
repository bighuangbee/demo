/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package rpc

import (
	"fmt"
	"net"
	"net/rpc"
)

func Run(addr string, name string, rcvr interface{}){
	fmt.Println("【RPC】Run ", addr, name)

	rpc.RegisterName(name, rcvr)
	rpc.HandleHTTP()

	listener, err := net.Listen("tcp", addr)
	if err != nil {
		fmt.Println("fatal error: ", err)
		panic("fatal error: " + err.Error())
	}

	go func() {
		for {
			conn, err := listener.Accept()
			if err != nil {
				fmt.Println("Accept error:", err)
			}
			rpc.ServeConn(conn)
		}
	}()
}

func Call(rpcAddr string, rpcname string, request interface{}, resp interface{}) bool {
	c, errx := rpc.Dial("tcp", rpcAddr)
	if errx != nil {
		return false
	}
	defer c.Close()

	err := c.Call(rpcname, request, resp)
	if err == nil {
		return true
	}

	fmt.Println("RPC Call", err)
	return false
}
