/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package mr

type KeyValue struct {
	Key   string
	Value string
}

type KeyValueSort []*KeyValue

func (a KeyValueSort) Len() int           { return len(a) }
func (a KeyValueSort) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a KeyValueSort) Less(i, j int) bool { return a[i].Key < a[j].Key }


type WordCount KeyValue
