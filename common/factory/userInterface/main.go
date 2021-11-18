/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"factory/userInterface/factory"
	"factory/userInterface/model"
	"fmt"
)

func main()  {
	Iuser := factory.UserFactory(model.UserApp)
	user:= Iuser.Create("weihua", "").(*model.User)
	fmt.Println(user.Name)

	admin := factory.UserFactory(model.UserAdmin).Create("admin", "adminroel").(*model.Admin)
	fmt.Println(admin.Name, admin.Role)
}
