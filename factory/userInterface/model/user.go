/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package model

const(
	UserApp = iota
	UserAdmin
)

type User struct {
	Id int
	Name string
}

func NewUser() *User {
	return &User{}
}

func (u *User)Create(name, role string) interface{} {
	return &User{Id: 1, Name: name}
}

type Admin struct {
	Id int
	Name string
	Role string
}

func NewAdmin() *Admin {
	return &Admin{}
}

func (u *Admin)Create(name, role string) interface{} {
	return &Admin{Id: 1, Name: name, Role: role}
}
