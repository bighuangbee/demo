/**
 * @desc //TODO $
 * @param $
 * @return $
 **/


package main

import (
	"fmt"
	"github.com/otiai10/gosseract/v2"
)

func main() {
	client := gosseract.NewClient()
	defer client.Close()
	client.SetImage("./image_1.png")
	client.SetLanguage("eng","chi_sim", "chi_tra")
	text, _ := client.Text()
	fmt.Println(text)

	box, err := client.GetBoundingBoxesVerbose()
	fmt.Println(err, box)
}
