/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package worker

import (
	"fmt"
	"sync"
)

type Task func()interface{}
type TaskResult func(interface{})interface{}

type Worker struct {
	WorkerCount int
	wg sync.WaitGroup
	Tasks chan Task
	Result chan TaskResult
}

func NewWorker(workerCount int) *Worker {
	return &Worker{WorkerCount: workerCount, wg: sync.WaitGroup{}, Tasks: make(chan Task, 128), Result: make(chan TaskResult, 3)}
}

func (this *Worker) Add(t Task) {
	this.Tasks <- t
}

func (this *Worker) do(cb TaskResult) {
	for i := 0; i < this.WorkerCount; i++ {
		this.wg.Add(1)
		go func(i int) {
			for task := range this.Tasks {
				result := task()
				cb(result)
			}
			fmt.Println("worker exit ", i)
			this.wg.Done()
		}(i)
	}
}

