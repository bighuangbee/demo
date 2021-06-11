/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import "fmt"

func main()  {
	test := make([]int, 0)
	for i:=0; i<10; i++ {
		test = append(test, i)
	}
	fmt.Println(test)

	test = nil
	fmt.Println(test)
}
