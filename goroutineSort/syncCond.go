/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"sync"
	"time"
)

func job3(){
	println("job3")
	time.Sleep(time.Millisecond*20)
	cond.Broadcast()
}
func job4(){
	cond.L.Lock()
	cond.Wait()
	defer cond.L.Unlock()
	println("job4")
	time.Sleep(time.Millisecond*0)
}
func job5(){
	cond.L.Lock()
	cond.Wait()
	defer cond.L.Unlock()
	println("job5")
	time.Sleep(time.Millisecond*0)
}


type JobGroup2 struct {
	*sync.WaitGroup
}

func(this *JobGroup2)do(fs ...func()){
	for _, fn := range fs {
		this.Add(1)
		go func(fn func()) {
			defer this.Done()
			fn()
		}(fn)
	}
}

var wg2 *JobGroup2

var cond *sync.Cond
func main()  {
	cond = sync.NewCond(&sync.Mutex{})
	wg2 = &JobGroup2{&sync.WaitGroup{}}
	wg2.do(job4,job5, job3, job4)
	wg2.Wait()

}
