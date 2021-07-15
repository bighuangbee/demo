/**
 * @desc 使用指定的协程数量，执行多个任务
 * @param $
 * @return $
 **/
package goroutinePool

import (
	"fmt"
	"sync"
	"time"
)

type TASK_FUNC func()interface{}

type Worker struct {
	TaskList chan *TASK_FUNC
	MaxCount int //最大协程数量
	Wg sync.WaitGroup
	exit chan struct{}
	Results chan interface{}
}

func NewWorker(maxCount int) *Worker {
	taskCount := 128
	return &Worker{MaxCount: maxCount, Wg: sync.WaitGroup{}, TaskList: make(chan *TASK_FUNC, taskCount), exit:make(chan struct{}, 1), Results: make(chan interface{}, taskCount)}
}

func (this *Worker)Add(taskFunc TASK_FUNC){
	this.TaskList <- &taskFunc
}

func (this *Worker) do(){
	for i := 0; i < this.MaxCount; i++ {
		this.Wg.Add(1)
		go func(gIndex int) {
			defer this.Wg.Done()
			for {
				select {
				case t := <- this.TaskList:
					if t == nil{break}
					result := (*t)()
					fmt.Println("do task in go", gIndex, ", result:", result)
					this.Results <- result

					time.Sleep(200*time.Millisecond)
					if len(this.TaskList) == 0{
						fmt.Println("task finished...")
						this.exit <- struct{}{}
					}
				case <-this.exit:
					return
				}
			}
		}(i)
	}

}

func (this *Worker) Run(resultCallback func(result interface{})){
	this.do()

	wg := sync.WaitGroup{}
	wg.Add(2)
	go func() {
		this.Wg.Wait()
		wg.Done()
		close(this.TaskList)
		time.Sleep(time.Second)
	}()

	go func() {
		wg.Done()
		for r := range this.Results{
			resultCallback(r)
		}
	}()

	wg.Wait()

}
