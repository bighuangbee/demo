/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"demo/MIT_lab/src/mr"
	"fmt"
	"os"
	"time"
)

func main() {
	if len(os.Args) < 2 {
		fmt.Println(os.Stderr, "filenames empty...")
		os.Exit(1)
	}

	nReduce := 3
	filenames := os.Args[1:]
	for mapTaskIndex, filename := range filenames{
		_, err := mr.DoMap(filename, mapTaskIndex, nReduce)
		if err != nil{
			fmt.Println("DoMap err:", err)
		}
	}

	t1 := time.Now()
	for reduceIndex := 0; reduceIndex < nReduce; reduceIndex++ {
		mr.DoReduce(len(os.Args[1:]), reduceIndex)
	}

	fmt.Println("DoReduce time:", time.Now().Sub(t1))

}
