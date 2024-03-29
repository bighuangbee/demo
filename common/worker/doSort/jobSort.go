/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"sync"
)

func job1(){
	println("job1")
	ch <- struct{}{}
}
func job2(){
	<- ch
	println("job2")
}

type JobGroup struct {
	*sync.WaitGroup
}

func(this *JobGroup)do(fs ...func()){
	for _, fn := range fs {
		this.Add(1)
		go func(fn func()) {
			defer this.Done()
			fn()
		}(fn)
	}
}

var wg *JobGroup
var ch chan struct{}

func main()  {
	wg = &JobGroup{&sync.WaitGroup{}}
	ch = make(chan struct{}, 2)

	wg.do(job1, job2)
	wg.Wait()

}
