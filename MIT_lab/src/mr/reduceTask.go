package mr

type ReduceTask struct {
	Task
}

func (m *ReduceTask) GetTask()*Task{
	return &Task{
		Status:    TaskStatusReduce,
		FileName:  m.FileName,
		StartTime: m.StartTime,
		Reduce: m.Reduce,
		TaskIndex: m.TaskIndex,
	}
}
