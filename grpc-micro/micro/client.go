/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"context"
	"fmt"
	pb "grpc-micro/proto"
	"github.com/asim/go-micro/v3/client"
	"os"
	"github.com/asim/go-micro/v3/registry"
	"github.com/asim/go-micro/plugins/registry/etcd/v3"
	"time"
)


func main()  {
	Hellohandler := pb.NewGreeterService("gomicro.srv.hello", NewClientDefault())

	time.AfterFunc(1* time.Second, func() {
		t1 := time.Now()
		Hellohandler.SayHello(context.Background(), &pb.HelloRequest{})
		fmt.Println(time.Now().Sub(t1))
	})

	for  {

	}
}

func NewClientDefault()(client.Client){
	opt := []client.Option{}
	if os.Getenv("MICRO_REGISTRY") == "etcd" && os.Getenv("MICRO_REGISTRY_ADDRESS") != ""{
		reg := etcd.NewRegistry()
		reg.Init(func(options *registry.Options) {
			options.Addrs = []string{os.Getenv("MICRO_REGISTRY_ADDRESS")}
		})
		opt = append(opt, client.Registry(reg))
	}
	opt = append(opt, client.ContentType("application/proto-rpc"))

	return client.NewClient(opt...)
}
