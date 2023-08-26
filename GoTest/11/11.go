/*
 * @Author: NEFU AB-IN
 * @Date: 2023-08-24 15:15:22
 * @FilePath: \GoTest\11\11.go
 * @LastEditTime: 2023-08-24 15:17:01
 */
package main

import (
	"fmt"
	"sync"
)

func hello(i int) {
	fmt.Println("hello goroutine : " + fmt.Sprint(i))
}

func HelloGoRoutine() {
	var wg sync.WaitGroup
	wg.Add(5)
	for i := 0; i < 5; i++ {
		go func(j int) {
			defer wg.Done()
			hello(j)
		}(i)
	}
	wg.Wait()
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
