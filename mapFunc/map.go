package main

import (
	"fmt"
	"strings"
)

func Map(data []string, fn func(string)string)[]string{
	results := []string{}
	for _, val := range data{
		results = append(results, fn(val))
	}
	return results
}

func main() {
	upStr := func(str string) string {
		return strings.ToUpper(str)
	}

	data := []string{"aa", "vv"}
	result := Map(data, upStr)
	fmt.Println(result)
}
