/*
 * @Author: NEFU AB-IN
 * @Date: 2023-08-24 15:15:22
 * @FilePath: \GoTest\10\10.go
 * @LastEditTime: 2023-08-24 15:15:31
 */
package main

import (
	"fmt"
	"time"
)

func hello(i int) {
	fmt.Println("hello goroutine : " + fmt.Sprint(i))
}

func HelloGoRoutine() {
	for i := 0; i < 5; i++ {
		go func(j int) {
			hello(j)
		}(i)
	}
	time.Sleep(time.Second)
}

func main() {
	HelloGoRoutine()
}

/*
 * hello goroutine : 4
 * hello goroutine : 2
 * hello goroutine : 1
 * hello goroutine : 3
 * hello goroutine : 0
 */
