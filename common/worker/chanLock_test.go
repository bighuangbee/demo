/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package worker

import (
	"fmt"
	"sync"
	"testing"
)

func TestLock(t *testing.T) {
	m := NewMutex()
	var n int

	var w sync.WaitGroup
	w.Add(10000)
	for i := 0; i < 10000; i++ {
		go func() {
			m.Lock()
			n ++
			m.Unlock()
			w.Done()
		}()
	}

	w.Wait()
	fmt.Println(n)
}
