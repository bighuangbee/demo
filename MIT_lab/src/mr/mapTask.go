/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package mr

type MapTask struct {
	Task
}

func (m *MapTask) GetTask()*Task {
	return &Task{
		Status:    TaskStatusMap,
		FileName:  m.FileName,
		StartTime: m.StartTime,
		Reduce: m.Reduce,
		TaskIndex: m.TaskIndex,
	}
}
