package main

import (
	"sync"
)

/*
条件变量 sync.Cond
sync.Cond 条件变量是基于互斥锁的，它必须有互斥锁的支撑才能发挥作用。
sync.Cond 条件变量用来协调想要访问共享资源的那些线程，当共享资源的状态发生变化的时候，它可以用来通知被互斥锁阻塞的线程
条件变量的初始化离不开互斥锁，并且它的方法也是基于互斥锁的
条件变量有三个方法，等待通知(wait),单发通知(signal),广播通知(broadcast)。当互斥锁锁定时，可以进行等待通知；当互斥锁解锁时，可以进行单发通知和广播通知。
var mailbox uint8
var lock sync.RWMutex
sendCond := sync.NewCond(&lock)
recvCond := sync.NewCond(lock.RLocker())

有几个点需要知道
sync.Cond 通过sync.NewCond(sync.Locker)初始化，初始化函数需要一个sync.Locker的参数值
sync.Locker其实是一个接口，包含Lock()和Unlock()方法。sync.Mutex和sync.RWMutex都有Lock和Unlock方法，只不过它们都是指针方法。因此，这两个类型的指针类型才是sync.Locker接口的实现类型
通过lock.RLock()获得读锁，这个读锁能调用lock变量的RLock和RUnlock方法，实现对读锁的解锁和锁定。
生产者，这里看作向mailbox产生值的对象
lock.Lock()
for mailbox == 1 {
    sendCond.Wait()
}
mailbox = 1
lock.Unlock()
recvCond.Signal()
消费者，向mailbox取值的对象
lock.RLock()
for mailbox == 0 {
 recvCond.Wait()
}
mailbox = 0
lock.RUnlock()
sendCond.Signal()

条件变量的Wait方法主要做了四件事。
把调用它的 goroutine（也就是当前的 goroutine）加入到当前条件变量的通知队列中。
解锁当前的条件变量基于的那个互斥锁。
让当前的 goroutine 处于等待状态，等到通知到来时再决定是否唤醒它。此时，这个 goroutine 就会阻塞在调用这个Wait方法的那行代码上。
如果通知到来并且决定唤醒这个 goroutine，那么就在唤醒它之后重新锁定当前条件变量基于的互斥锁。自此之后，当前的 goroutine 就会继续执行后面的代码了。
if语句只会对共享资源的状态检查一次，而for语句却可以做多次检查，直到这个状态改变为止。那为什么要做多次检查呢？这主要是为了保险起见。如果一个 goroutine 因收到通知而被唤醒，但却发现共享资源的状态，依然不符合它的要求，那么就应该再次调用条件变量的Wait方法，并继续等待下次通知的到来。
在 Go 语言中，我们需要用sync.NewCond函数来初始化一个sync.Cond类型的条件变量。
sync.NewCond函数需要一个sync.Locker类型的参数值。

sync.Mutex类型的值以及sync.RWMutex类型的值都可以满足这个要求。都可以满足这个要求。另外，后者的RLocker方法可以返回这个值中的读锁，也同样可以作为sync.NewCond函数的参数值，如此就可以生成与读写锁中的读锁对应的条件变量了。

条件变量的Wait方法需要在它基于的互斥锁保护下执行，否则就会引发不可恢复的 panic。此外，我们最好使用for语句来检查共享资源的状态，并包裹对条件变量的Wait方法的调用。

不要用if语句，因为它不能重复地执行”检查状态 - 等待通知 - 被唤醒“的这个流程。重复执行这个流程的原因是，一个因等待通知，而被阻塞的 goroutine，可能会在共享资源的状态不满足其要求的情况下被唤醒。

条件变量的Signal方法只会唤醒一个因等待通知而被阻塞的 goroutine，而它的Broadcast方法却可以唤醒所有为此而等待的 goroutine。后者比前者的适应场景要多得多。

这两个方法并不需要受到互斥锁的保护，我们也最好不要在解锁互斥锁之前调用它们。还有，条件变量的通知具有即时性。当通知被发送的时候，如果没有任何 goroutine 需要被唤醒，那么该通知就会立即失效。
*/
func job3(){
	println("job3")
	cond.Broadcast()
}
func job4(){
	cond.L.Lock()
	cond.Wait()
	defer cond.L.Unlock()
	println("job4")
}
func job5(){
	cond.L.Lock()
	cond.Wait()
	defer cond.L.Unlock()
	println("job5")
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
