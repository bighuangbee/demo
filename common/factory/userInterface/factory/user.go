/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package factory

import "factory/userInterface/model"

type IUser interface {
	Create(name, role string)interface{}
}

func UserFactory(t int) IUser {
	switch t {
	case model.UserApp:
		return model.NewUser()
	case model.UserAdmin:
		return model.NewAdmin()
	default:
		return model.NewUser()
	}
}
