/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package scheduler

import (
	"demo/MIT_lab/src/rpc"
	"fmt"
	"time"
)

type Task struct {
	Name string
}

type TaskQueue struct{
	Queue []*Task
}

func (this *TaskQueue)Pop()*Task{
	if len(this.Queue) == 0{
		return nil
	}

	t := this.Queue[0]
	this.Queue = this.Queue[1:]
	return t
}

func (this *TaskQueue)Push(t *Task){
	this.Queue = append(this.Queue, t)
}

type Scheduler struct {
	TaskQueue TaskQueue //任务队列

	ExitChan chan struct{} //退出chan

	WorkerReady chan *Master
}

var MasterScheduler *Scheduler

func init(){
	MasterScheduler = NewScheduler()
}

func NewScheduler() *Scheduler {
	return &Scheduler{
		TaskQueue:   TaskQueue{},
		ExitChan:    make(chan struct{}),
		WorkerReady: make(chan *Master, 10),
	}
}

func (this *Scheduler)Schedule(){
	for{
		select{
			case worker := <- this.WorkerReady: {
				t1 := time.Now()

				task := this.TaskQueue.Pop()
				if task != nil{
					ok := rpc.Call(worker.Address, WorkerSvcName+".Do", &WorkerReq{TaskName: task.Name}, new(struct{}))
					if ok {
						this.WorkerReady <- worker
					}
					fmt.Println("【Scheduler】Schedule", task.Name, worker.Address, time.Now().Sub(t1), ok)
				}else{
					fmt.Println("【Scheduler】task done")
					go func() {
						this.ExitChan <- struct{}{}
					}()
					return
				}
			}
		}
	}
}

