/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"fmt"
	"time"
)

type Config struct {
	Timeout time.Duration
	MaxConn int64
}

type Server struct {
	Port int
	Config *Config
}

type Option func(server *Server)

func NewServer(port int, options ...Option) *Server {
	s := &Server{Port: port, Config: &Config{}}

	for _, option := range options{
		option(s)
	}
	return s
}

func WithTimeout(t time.Duration) Option {
	return func(server *Server) {
		server.Config.Timeout = t * time.Second
	}
}

func main()  {
	s := NewServer(10, WithTimeout(10))
	fmt.Println(s.Port, s.Config.Timeout)
}

