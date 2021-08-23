/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"demo/MIT_lab/src/rpc"
	"demo/MIT_lab/src/scheduler"
	"fmt"
	"os"
	"time"
)

func main(){
	args := os.Args
	if len(args) < 3{
		fmt.Println("worker args incorrect")
		return
	}

	masterAddr := args[1]
	workerAddr := args[2]

	go rpc.Run(workerAddr, scheduler.WorkerSvcName, scheduler.NewWorker(workerAddr))

	time.AfterFunc(200*time.Millisecond, func() {
		retisteToMaster(masterAddr, workerAddr)
	})

	for{}
}

func retisteToMaster(masterAddr, workerAddr string){
	r := scheduler.WorkerRegisterRequest{Addr: workerAddr}
	ok := rpc.Call(masterAddr, scheduler.MasterSvcName + ".Registe", &r, new(struct{}))
	fmt.Printf("【worker】%s registe result: %t\n", workerAddr, ok)
}
