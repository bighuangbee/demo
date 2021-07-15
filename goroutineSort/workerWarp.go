/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

type WorkerFunc func()interface{}

type WorkerWarp struct {
	wg         *sync.WaitGroup
	results    chan interface{}
	workerPool []WorkerFunc
	poolSize 	int
}

func (this *WorkerWarp) Add(worker WorkerFunc)  {
	this.workerPool = append(this.workerPool, worker)
}

func (this *WorkerWarp)do(){
	for _, fn := range this.workerPool {
		this.wg.Add(1)
		go func(f WorkerFunc) {
			defer this.wg.Done()
			t := f()
			this.results <- t
		}(fn)
	}
}

func (this *WorkerWarp)Range(callback func(interface{})){
	go func() {
		this.wg.Wait()
		//工作线程执行完毕 关闭通道
		defer close(this.results)
	}()
	this.do()

	//等待工作线程将执行的结果放入通道，然后执行回调函数将结果返回出去
	for item := range this.results{
		callback(item)
	}
}

func NewWorkerWarp()*WorkerWarp{
	return &WorkerWarp{
		wg:         &sync.WaitGroup{},
		results:    make(chan interface{}),
		poolSize:   3,
	}
}

func main(){
	startTime := time.Now()


	workerWarp := NewWorkerWarp()

	taskCount := 5
	for i:=0; i< taskCount; i++{
		workerWarp.Add(func() interface{} {
			time.Sleep(time.Second*time.Duration(rand.Intn(3)))
			return rand.Intn(10)
		})
	}

	total := 0
	workerWarp.Range(func(i interface{}){
		total += i.(int)
		fmt.Println("range result:", i)
	})

	defer fmt.Println("program run time:", time.Now().Sub(startTime), "total:",total)
}
