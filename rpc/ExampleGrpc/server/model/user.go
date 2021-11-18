/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package model

import "gopackage/storage"

type User struct {
	storage.Model       `gorm:"embedded"`
	Username            string `json:"username" gorm:"username" update:"username"`
	Nickname            string `json:"nickname" gorm:"nickname" update:"nickname"`
	Email               string `json:"email" gorm:"email" update:"email"`
	Password            string `json:"password" gorm:"password" update:"password"`
	storage.UpdateEmbed `gorm:"embedded"`
}
