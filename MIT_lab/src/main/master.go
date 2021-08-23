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

func main()  {
	args := os.Args
	if len(args) < 2{
		fmt.Println("args incorrect")
		return
	}


	scheduler.MasterScheduler.TaskQueue.Push(&scheduler.Task{Name: "map"})
	scheduler.MasterScheduler.TaskQueue.Push(&scheduler.Task{Name: "reduce"})
	scheduler.MasterScheduler.TaskQueue.Push(&scheduler.Task{Name: "map"})
	scheduler.MasterScheduler.TaskQueue.Push(&scheduler.Task{Name: "map"})


	master := scheduler.Master{Address: args[1]}
	go rpc.Run(args[1], scheduler.MasterSvcName, &master)

	fmt.Println("【master】svc listen ", args[1])

	go scheduler.MasterScheduler.Schedule()

	<- scheduler.MasterScheduler.ExitChan
	os.Exit(1)
}
