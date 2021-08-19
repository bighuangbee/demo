// Code generated by protoc-gen-micro. DO NOT EDIT.
// source: helloworld.proto

package helloworld

import (
	fmt "fmt"
	proto "google.golang.org/protobuf/proto"
	math "math"
)

import (
	context "context"
	api "github.com/asim/go-micro/v3/api"
	client "github.com/asim/go-micro/v3/client"
	server "github.com/asim/go-micro/v3/server"
)

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// Reference imports to suppress errors if they are not otherwise used.
var _ api.Endpoint
var _ context.Context
var _ client.Option
var _ server.Option

// Api Endpoints for Greeter service

func NewGreeterEndpoints() []*api.Endpoint {
	return []*api.Endpoint{}
}

// Client API for Greeter service

type GreeterService interface {
	// Sends a greeting
	SayHello(ctx context.Context, in *HelloRequest, opts ...client.CallOption) (*HelloReply, error)
}

type greeterService struct {
	c    client.Client
	name string
}

func NewGreeterService(name string, c client.Client) GreeterService {
	return &greeterService{
		c:    c,
		name: name,
	}
}

func (c *greeterService) SayHello(ctx context.Context, in *HelloRequest, opts ...client.CallOption) (*HelloReply, error) {
	req := c.c.NewRequest(c.name, "Greeter.SayHello", in)
	out := new(HelloReply)
	err := c.c.Call(ctx, req, out, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

// Server API for Greeter service

type GreeterHandler interface {
	// Sends a greeting
	SayHello(context.Context, *HelloRequest, *HelloReply) error
}

func RegisterGreeterHandler(s server.Server, hdlr GreeterHandler, opts ...server.HandlerOption) error {
	type greeter interface {
		SayHello(ctx context.Context, in *HelloRequest, out *HelloReply) error
	}
	type Greeter struct {
		greeter
	}
	h := &greeterHandler{hdlr}
	return s.Handle(s.NewHandler(&Greeter{h}, opts...))
}

type greeterHandler struct {
	GreeterHandler
}

func (h *greeterHandler) SayHello(ctx context.Context, in *HelloRequest, out *HelloReply) error {
	return h.GreeterHandler.SayHello(ctx, in, out)
}