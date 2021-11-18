package main

import (
	"fmt"
	"golang.org/x/net/context"
	"gopackage/common"
	"gopackage/config"
	"gopackage/network/rpc"
	"gopackage/storage"
	"rpc/ExampleGrpc/server/model"
	"rpc/proto/pb"
	"time"
)

func init()  {
	config.New("config.yaml", "../conf")
}

type server struct {
	pb.UnimplementedUserServiceServer
}

func (s *server) Create(ctx context.Context, in *pb.User) (*pb.UserRes, error){
	password := ""
	status := int32(0)

	in = &pb.User{
		Username:   "weihuahuang",
		Role:       []string{"1"},
		Password:   password,
		Nickname:   nil,
		CreateUserId: "admin",
		CreateTime:   "2020-10-10",
		Status: &status,
	}


	m := common.PbToMap(in)
	fmt.Println("----Create:", in)
	fmt.Println("----model.User m:", m)
	return &pb.UserRes{UserId: 10086}, nil
}

func (s *server) Get(ctx context.Context, in *pb.User) (*pb.User, error){
	u := model.User{
		Model:       storage.Model{ID: 100},
		Username:    "wei",
		Nickname:    "hua",
		Email:       "",
		Password:    "123123",
		UpdateEmbed: storage.UpdateEmbed{UpdateTime: storage.Time(time.Now()), UpdateUserId: storage.Time(time.Now())},
	}


	resp := pb.User{}
	common.StructTransform(&u, &resp)
	fmt.Println("----get model:", u)
	fmt.Println("----resp pb:", resp.Id, resp.Username, resp.Nickname, resp.Email, resp.Password, resp.CreateUserId)
	fmt.Println("---", resp.Email == "")
	return &pb.User{}, nil
}

func main() {
	(&server{}).Create(context.Background(), &pb.User{})
	//(&server{}).Get(context.Background(), &pb.User{})

	s := rpc.NewGrpcServer(config.C.GetString("ExampleGrpcPort"), config.C.GetString("ExampleGrpc"))
	pb.RegisterUserServiceServer(s.Server, &server{})
	s.Serve()
}
