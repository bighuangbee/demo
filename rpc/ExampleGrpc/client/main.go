/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"fmt"
	"golang.org/x/net/context"
	"gopackage/config"
	"gopackage/network/rpc"
	"log"
	"rpc/proto/pb"
	"time"
)


func main() {
	config.New("config.yaml","../conf")

	conn, err := rpc.NewGrpcConn(config.C.GetString("ExampleGrpcAddr"))
	if err != nil{
		return
	}

	c := pb.NewUserServiceClient(conn)

	t1 := time.Now()
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()

	nickname := ""
	r, err := c.Create(ctx, &pb.User{
		Username:   "bighuangbee",
		Email:      "email",
		Role:       nil,
		Password:   "1234",
		Nickname:   &nickname,
		CreateUserId: "admin",
		CreateTime:   "2020-10-10",
	})
	if err != nil {
		log.Fatalf("could not greet: %v", err)
	}
	log.Printf("create user: %d", r.UserId)

	fmt.Println("time:",time.Now().Sub(t1))
}
