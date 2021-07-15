/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package goroutinePool

import (
	"fmt"
	"math/rand"
	"testing"
)

func TestWorker(t *testing.T) {
	worker := NewWorker(3)

	w1 := func() interface{}{
		res := rand.Intn(5)
		return res
	}

	for i := 0; i < 10; i++ {
		worker.Add(w1)
	}

	total := 0
	resultCallback := func(res interface{}) {
		total += res.(int)
	}
	worker.Run(resultCallback)

	fmt.Println("total:",total)

	for{

	}

}
