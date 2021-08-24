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
)

/**
 * @Description:
 go run worker.go masterAddr masterAddr
 go run worker.go localhost:2001 localhost:3001
 */

var masterAddr string
var workerAddr string

func init(){
	args := os.Args
	if len(args) < 3{
		fmt.Println("worker args incorrect")
		return
	}

	masterAddr = args[1]
	workerAddr = args[2]

	rpc.Run(workerAddr, scheduler.WorkerSvcName, scheduler.NewWorker(workerAddr))
}

func main(){
	scheduler.RetisteToMaster(masterAddr, workerAddr)

	for{}
}


