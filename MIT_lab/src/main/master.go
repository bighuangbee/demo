/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"demo/MIT_lab/src/mr"
	"demo/MIT_lab/src/rpc"
	"demo/MIT_lab/src/scheduler"
	"fmt"
	"os"
	"time"
)

/**
 * @Description:
 go run master.go localhost:2001
 */
func main()  {

	t1 := time.Now()

	filenames := []string{}

	args := os.Args
	if len(args) < 2{
		fmt.Println("args incorrect")
		return
	}else{
		filenames = args[2:]
	}

	masterAddr := args[1]
	master := scheduler.NewMaster(masterAddr, 3)

	GenTask(master, filenames)

	rpc.Run(args[1], scheduler.MasterSvcName, master)
	fmt.Println("【master】svc listen ", masterAddr)

	go master.Scheduler.Schedule(master.Reduce)

	<- master.Scheduler.ExitChan

	fmt.Println("master runtime:", time.Now().Sub(t1))
	os.Exit(1)
}

func GenTask(master *scheduler.Master, filenames []string){
	if len(filenames) != 0{
		for index, filename := range filenames {
			var task mr.ITask
			task = &mr.MapTask{Task: mr.Task{
				Status:    mr.TaskStatusMap,
				FileName:  []string{filename},
				TaskIndex: index,
				Reduce: master.Reduce,
			}}
			master.Scheduler.TaskQueue.Push(task)
		}
	}else{
		for i := 0; i < 10; i++ {
			var task mr.ITask
			if i % 3 == 0{
				task = &mr.ReduceTask{}
			}else{
				task = &mr.MapTask{}
			}
			master.Scheduler.TaskQueue.Push(task)
		}
	}

}
