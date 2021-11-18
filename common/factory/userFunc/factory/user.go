/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package factory

import "factory/userFunc/model"

func UserCreate(t int) model.UserCreateFunc {
	switch t {
	case model.UserApp:
		return model.NewUser()
	case model.UserAdmin:
		return model.NewAdmin()
	default:
		return model.NewUser()
	}
}
