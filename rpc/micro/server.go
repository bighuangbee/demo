/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"context"
	"github.com/asim/go-micro/v3"
	"github.com/asim/go-micro/v3/registry"
	"log"
	"os"
	"rpc/proto/pb"
)

type Hellohandler struct {
}


func (this *Hellohandler) SayHello(c context.Context, in *pb.HelloRequest, resp *pb.HelloReply) error {

	resp.Message = "go micro: hello"
	return nil
}


func main(){

	svc := NewServiceDefault("gomicro.srv.hello")

	h := Hellohandler{}
	pb.RegisterGreeterHandler(svc.Server(), &h)

	if err := svc.Run(); err != nil {
		log.Panic("service run faild", err)
	}
}

func NewServiceDefault(srvName string)(micro.Service){

	service := micro.NewService(
		micro.Name(srvName),
		micro.Version("DefaultVersion"))

	opt := []micro.Option{}
	if os.Getenv("MICRO_REGISTRY") == "etcd" && os.Getenv("MICRO_REGISTRY_ADDRESS") != ""{
		opt = append(opt, micro.Registry(EtcdRegistry()))
	}
	service.Init(opt...)
	return service
}

func EtcdRegistry()registry.Registry{
	reg := registry.NewRegistry()
	reg.Init(func(options *registry.Options) {
		options.Addrs = []string{os.Getenv("MICRO_REGISTRY_ADDRESS")}
	})
	return reg
}
