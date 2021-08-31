/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package goroutineChan

import (
	"fmt"
	"sync"
)

type WorkerFunc func()interface{}

type WorkerWarper struct {
	workerCount int //工作线程数
	wg sync.WaitGroup
	WorkerQueue chan WorkerFunc
	ResultsChan chan WorkerFunc
	ExitChan chan struct{}
}

func NewWorkerWarper(workerCount int) *WorkerWarper {
	return &WorkerWarper{
		workerCount: workerCount,
		wg: sync.WaitGroup{},
		WorkerQueue: make(chan WorkerFunc, 128),
		ResultsChan: make(chan WorkerFunc, 5),
	}
}

func (this *WorkerWarper) Add(worker WorkerFunc) {
	this.WorkerQueue <- worker
}

func (this *WorkerWarper) Close() {
	close(this.WorkerQueue)
}


func (this *WorkerWarper) do(callback func(interface{})interface{}) {
	for i := 0; i < this.workerCount; i++ {
		this.wg.Add(1)
		go func(i int) {
			defer this.wg.Done()
			for worker := range this.WorkerQueue {
				result := worker()
				callback(result)
			}
			fmt.Println("worker exit", i)
		}(i)
	}
}
