/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"factory/userFunc/factory"
	"factory/userFunc/model"
	"fmt"
)

/**
 工厂方法返回创建对象的函数
 外部直接调用创建函数
 */
func main()  {
	user := factory.UserCreate(model.UserApp)("weihua", "").(*model.User)
	fmt.Println(user.Name)

	admin := factory.UserCreate(model.UserAdmin)("admin", "adminrole").(*model.Admin)
	fmt.Println(admin.Name, admin.Role)
}
