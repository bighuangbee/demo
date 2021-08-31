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

type Task func()interface{}
type TaskResult func(interface{})interface{}

type TaskWorker struct {
	WorkerCount int
	wg sync.WaitGroup
	Tasks chan Task
	Result chan TaskResult
}

func NewTaskWorker(workerCount int) *TaskWorker {
	return &TaskWorker{WorkerCount: workerCount, wg: sync.WaitGroup{}, Tasks: make(chan Task, 128), Result: make(chan TaskResult, 3)}
}

func (this *TaskWorker) AddTask(t Task) {
	this.Tasks <- t
}

func (this *TaskWorker) do(cb TaskResult) {
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

