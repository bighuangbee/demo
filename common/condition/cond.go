/**
 * @desc //TODO $
 * @param $
 * @return $
 **/

package main

import (
	"fmt"
"runtime"
"sync"
)

/**
cond.Wait()的操作实际上是对与cond绑定的锁先进行解锁，在等待通知；接收到通知后，会尝试加锁，加锁成功则唤醒否则继续等待通知；
cond.Waite()前必须对关连锁加锁，否则panic
下面例子中用的读写锁，也可以直接用互斥锁，使用场景不同而已
例子中如果有多个f1在不同goruntine中执行，f2中可以使用cond.Broadcast进行广播唤醒所有f1，如果是互斥锁肯定只有一个f1运行实体会重新获取到锁；而如果是读写锁则所有f1实体都可以成功RLock
使用runtime.Gosched()是为了让go f1()这个goruntine先执行，否则go f2()可能先运行结束，此时程序的go f1()和主goruntine都在处于asleep状态，会panic
 */
func main() {
	var num int
	mu := new(sync.RWMutex)
	cond := sync.NewCond(mu.RLocker())
	var wg sync.WaitGroup
	wg.Add(4)
	f1 := func() {
		mu.RLock()
		fmt.Println("f1 waiting")
		cond.Wait()
		fmt.Println("f1:", num)
		mu.RUnlock()
		wg.Done()
	}
	f2 := func() {
		mu.Lock()
		num = num + 1
		mu.Unlock()
		fmt.Println("f2 lock, signal")
		cond.Broadcast()
		fmt.Println("f2 go on")
		wg.Done()
	}


	go f1()
	runtime.Gosched()
	go f2()
	go f2()
	go f2()
	wg.Wait()
	fmt.Println("end")
}
