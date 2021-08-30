/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package goroutinePool

import (
	"fmt"
	"math/rand"
	"sync/atomic"
	"testing"
)

/*
1、go没有提供内置方法检测chan是否已经关闭了
2、对已关闭的chan进行close会导致panic（重复关闭chan）
3、对已关闭的chan进行写操作会导致panic，读操作不受影响

关闭chan原则：
不要在接收端关闭chan，也不要在多个并发的发送端中关闭chan。
所以正确的做法是，在唯一的发送端或多个发送端的最后一个当中进行关闭。

*/

//特殊情况下必须在接收端或发送端中关闭chan，可以使用recover拦截发送或关闭chan的操作而产生panic，避免引起主程序的异常，实现安全的发送或接收
func TestSafe(t *testing.T)  {
	ch := make(chan T, 10)

	fmt.Println("SafeSend:",SafeSend(ch, T(12)))

	close(ch)

	fmt.Println("SafeSend:",SafeSend(ch, T(10)))

	SafeClose(ch)
}

//一个发送者，多个接收者，在数据发送完毕后在发送端关闭chan
func TestName(t *testing.T) {
	worker := NewWorkerWarper(3)

	fn := func() interface{} {
		return rand.Int31n(5)
	}

	go func() {
		taskCount := 10
		for i := 0; i < taskCount; i++ {
			worker.Add(fn)
		}

		//最后一个发送操作完成后，关闭chan
		worker.Close()
	}()

	total := int32(0)
	cb := func(result interface{}) interface{}{
		fmt.Println("result:", result)
		atomic.AddInt32(&total, result.(int32))
		return atomic.LoadInt32(&total)
	}
	worker.do(cb)

	worker.wg.Wait()

	fmt.Println("total:", total)
}
