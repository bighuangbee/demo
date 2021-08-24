package mr

import "time"

type ITask interface {
	GetTask()*Task
}

const(
	TaskStatusMap = iota
	TaskStatusReduce
	TaskStatusWaiting
	TaskStatusEnd
)

type Task struct {
	Status int
	FileName []string
	StartTime time.Duration
	TaskIndex int //当前任务的索引
	Reduce int	//启动多少个reduce
}
