/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package scheduler

import (
	mr2 "demo/MIT-6.824-master/src/mr"
	"demo/MIT_lab/src/mr"
	"demo/MIT_lab/src/rpc"
	"fmt"
	"time"
)


type TaskQueue struct{
	Queue []mr.ITask
}

func (this *TaskQueue)Pop()mr.ITask{
	if len(this.Queue) == 0{
		return nil
	}

	t := this.Queue[0]
	this.Queue = this.Queue[1:]
	return t
}

func (this *TaskQueue)Push(t mr.ITask){
	this.Queue = append(this.Queue, t)
}

type Scheduler struct {
	TaskQueue TaskQueue //任务队列

	ExitChan chan struct{} //退出chan

	WorkerReady chan *Worker
}


func NewScheduler() *Scheduler {
	return &Scheduler{
		TaskQueue:   TaskQueue{},
		ExitChan:    make(chan struct{}),
		WorkerReady: make(chan *Worker, 10),
	}
}

func (this *Scheduler) JoinWorker(worker *Worker){
	go func() {
		this.WorkerReady <- worker
	}()
}

func (this *Scheduler)Schedule(taskCount int){
	for i := 0; i < taskCount; i++ {
		go func(reduceIndex int) {
			for{
				worker := <- this.WorkerReady
				t1 := time.Now()
				iTask := this.TaskQueue.Pop()
				if iTask != nil{
					task := iTask.GetTask()

					ok := rpc.Call(worker.Addr, WorkerSvcName+".Do", task, new(struct{}))
					if ok {
						if task.Status == mr.TaskStatusMap{
							reduceTask := mr.ReduceTask{Task: mr.Task{
								Status:    mr2.TaskReduce,
								TaskIndex: taskCount,
								Reduce:    reduceIndex,
							}}
							this.TaskQueue.Push(&reduceTask)
						}

						this.JoinWorker(worker)
					}
					fmt.Println("【Scheduler】Schedule", worker.Addr, task.Status, time.Now().Sub(t1), ok, task.Reduce)
				}else{
					fmt.Println("【Scheduler】task done")
					this.Exit()
					return
				}
			}
		}(i)
	}
}

func (this *Scheduler)Exit(){
	go func() {
		this.ExitChan <- struct{}{}
	}()
}
