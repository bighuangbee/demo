/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"context"
	"fmt"
	"time"
)

func f1(ctx context.Context){

	done := make(chan struct{}, 1)
	go func() {
		time.AfterFunc(time.Second*time.Duration(5), func() {
			done <- struct{}{}
		})
	}()

	select {
		case <-ctx.Done():
			fmt.Println("context done.", ctx.Err())
		case <-done:
			fmt.Println("worker done", ctx.Err())
	}
}

func main(){
	ctx, cancel := context.WithTimeout(context.Background(), time.Second*2)
	go f1(ctx)

	time.AfterFunc(time.Second*time.Duration(3), func() {
		fmt.Println("time to cancel.")
		cancel()
	})

	for{}
}
