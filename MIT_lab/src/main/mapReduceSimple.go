/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"demo/MIT_lab/src/mr"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"os"
	"time"
)

func main() {
	if len(os.Args) < 2 {
		fmt.Println(os.Stderr, "filenames empty...")
		os.Exit(1)
	}

	maps, err := mr.DoMap(os.Args[1:])
	if err != nil{
		fmt.Println("DoMap err:", err)
	}

	a,_ := json.Marshal(maps)
	ioutil.WriteFile(mr.OutputPath + "mrSimpleKV.txt", a, 0755)

	oname := mr.OutputPath + "mrSimple-out-0.txt"
	ofile, _ := os.Create(oname)
	defer ofile.Close()

	t1 := time.Now()
	wordCount := mr.DoReduce(maps)
	for _, word := range wordCount {
		line := word.Key + ": " + word.Value + "\n"
		ofile.Write([]byte(line))
	}
	fmt.Println("1 DoReduce time:", time.Now().Sub(t1).Microseconds(), ", word total:", len(wordCount))

	//t2 := time.Now()
	//wordCount = mr.DoReduce1(intermediate)
	//for _, word := range wordCount {
	//	line := word.Key + ": " + word.Value + "\n"
	//	ofile.Write([]byte(line))
	//}
	//fmt.Println("2 DoReduce time:", time.Now().Sub(t2).Microseconds(), ", word total:", len(wordCount))

}
