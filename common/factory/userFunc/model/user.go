/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package model

type UserCreateFunc func(name, role string)interface{}

const(
	UserApp = iota
	UserAdmin
)

type User struct {
	Id int
	Name string
}

func NewUser() UserCreateFunc {
	return func(name, role string) interface{} {
		return &User{Id: 1, Name: name}
	}
}

type Admin struct {
	Id int
	Name string
	Role string
}

func NewAdmin() UserCreateFunc {
	return func(name, role string) interface{} {
		return &Admin{Id: 2, Name: name, Role: role}
	}
}
