package main

import (
	"demo/byteCopy/byteCopy"
	"strconv"
	"sync"
	"testing"
)

func Benchmark_ByteCopy(b *testing.B) {
	buf := "aaaaaaaaaaaaaa_"
	for i := 0; i < b.N; i++ {
		buf += strconv.Itoa(i)
		byteCopy.TestframeCallBack(buf)
	}

}

func Test_ByteCopy(b *testing.T) {
	wg := sync.WaitGroup{}
	buf := "aaaaaaaaaaaaaa_"
	for i:=0; i<10; i++{
		wg.Add(1)

		go func(index int) {
			defer wg.Done()
			 //buf += strconv.Itoa(index)
			byteCopy.TestframeCallBack(buf)
			buf = ""
		}(i)
	}

	wg.Wait()

}