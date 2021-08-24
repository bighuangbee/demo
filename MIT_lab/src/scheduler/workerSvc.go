/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package scheduler

import (
	"demo/MIT_lab/src/mr"
	"demo/MIT_lab/src/rpc"
	"fmt"
)

type Worker struct {
	Addr string // worker addr
}

func NewWorker(addr string) *Worker {
	return &Worker{Addr: addr}
}


type WorkerTaskResp struct {
}

func (t *Worker)Do(task mr.Task, resp *WorkerTaskResp) error {

	fmt.Printf("【Worker】%s, DoTask Name: %d FileName: %s, Reduce: %d\n", t.Addr, task.Status, task.FileName,task.Reduce)

	for _, filename := range task.FileName {
		if task.Status == mr.TaskStatusMap{
			mr.DoMap(filename, task.TaskIndex, task.Reduce)
		}else{
			mr.DoReduce(task.TaskIndex, task.Reduce)
		}
	}
	//time.Sleep(1000 * time.Millisecond)
	return nil
}


func RetisteToMaster(masterAddr, workerAddr string){
	r := WorkerRegisterRequest{Addr: workerAddr}
	ok := rpc.Call(masterAddr, MasterSvcName + ".Registe", &r, new(struct{}))
	fmt.Printf("【worker】%s registe result: %t\n", workerAddr, ok)
}
