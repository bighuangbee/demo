/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package scheduler

import (
	"fmt"
	"math/rand"
	"time"
)

type Worker struct {
	Addr string // worker addr
}

func NewWorker(addr string) *Worker {
	return &Worker{Addr: addr}
}

type WorkerReq struct {
	TaskName string
}

type WorkerTaskResp struct {
}

func (t *Worker)Do(req WorkerReq, resp *WorkerTaskResp) error {
	fmt.Printf("【Worker】%s, DoTask Name: %s\n", t.Addr, req.TaskName)
	time.Sleep(time.Duration(rand.Intn(2000)) * time.Millisecond)
	return nil
}
