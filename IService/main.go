package main

import (
	"fmt"
)

type Handler struct {
	repo Repository
	auth Auth
}
type Repository interface {
	Create(name string)
}
type Db struct {
	Connect string
}
/* Db实现Repository接口的Create方法，所以Db类型拥有了Repository接口，就可以将Db值赋值给Repository接口 */
func (db *Db)Create(name string){
	fmt.Println("Create user:", name)
}

type Auth interface {
	Decode(token string)
}
type TokenService struct {
	 repo Repository
}
func (s *TokenService)Decode(token string){
	fmt.Println("decode token:", token)
}

/*
TokenService实现了Auth接口， repo字段类型为Repository，是一个接口类型
而Db实现了Repository接口，所以Db可以赋值给TokenService的repo字段
*/

func main() {
	db := &Db{Connect: "mysql"}

	h := Handler{repo: db, auth: &TokenService{repo: db}}
	h.repo.Create("wangxiaohu")
	h.auth.Decode("token 111")
}