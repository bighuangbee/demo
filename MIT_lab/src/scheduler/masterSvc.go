/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package scheduler

import "fmt"

type WorkerRegisterRequest struct {
	Addr string
}

type WorkerRegisterResp struct {
}


type Master struct {
	Address string
}


func (m *Master)Registe(req WorkerRegisterRequest, resp *WorkerRegisterResp) error {
	go func() {
		MasterScheduler.WorkerReady <- &Master{Address: req.Addr}
		fmt.Println("==---worker size:", len(MasterScheduler.WorkerReady))
	}()
	return nil
}
