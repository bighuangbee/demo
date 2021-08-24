/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package scheduler

type WorkerRegisterRequest struct {
	Addr string
}

type WorkerRegisterResp struct {
}


type Master struct {
	Address string
	Scheduler *Scheduler
	Reduce int //启动多少个reduce
}

func NewMaster(address string, nDeduce int) *Master {
	return &Master{Address: address, Scheduler: NewScheduler(), Reduce: nDeduce}
}

func (m *Master)Registe(req WorkerRegisterRequest, resp *WorkerRegisterResp) error {
	m.Scheduler.JoinWorker(NewWorker(req.Addr))
	return nil
}
