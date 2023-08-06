/*
 * @Author: NEFU AB-IN
 * @Date: 2023-08-06 09:44:15
 * @FilePath: \GoTest\1.go
 * @LastEditTime: 2023-08-06 22:57:59
 */
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func Read[T any]() T {
	var i T
	fmt.Fscan(in, &i)
	return i
}

const N int = 1e5 + 10

// 函数
func add(a int, b int) (v int, ok bool) {
	return a + b, ok
}

func add2(a *int) {
	*a += 2
}

// 结构体
type sa struct {
	x int
	y int
}

// 结构体方法（类成员函数）
func (a sa) add(x int) bool {
	return a.x == 2
}

func main() {
	defer out.Flush()

	// 1. variable
	a := "123"
	var b int = 2
	var c int64
	/*
		int   类型大小为 8 字节
		int8  类型大小为 1 字节
		int16 类型大小为 2 字节
		int32 类型大小为 4 字节
		int64 类型大小为 8 字节
	*/
	var d float64

	e := a + "foo"

	const s = "1231"

	fmt.Println(a, b, c, d) // 带换行
	fmt.Print(s)            // 不带换行
	fmt.Println(e)

	// 2. if else

	f := Read[int]()
	if f%2 == 0 {
		print("even")
	} else {
		print("odd")
	}

	// 3. 循环
	for i := 0; i < 10; i++ {
		fmt.Print("!")
	}

	// 4. 数组 两种声明方式
	var g [N]int
	var h = [N]int{}
	fmt.Println(g[1:2], h[2:3])

	// 5. slice 切片
	j := make([]string, 3)
	j = append(j, "cc")
	fmt.Println(j[2:5])

	// 6. map
	mp := map[string]int{}
	mp["xw"] = 100
	mp["lsy"] = 12
	l, ok := mp["xw"]
	fmt.Println(l, ok)

	delete(mp, "xw")
	for key, val := range mp {
		fmt.Println(key, val)
	}

	// 7. 给构体
	m := sa{x: 10}
	fmt.Println(m)

	// 8. 格式化
	fmt.Printf("f=%v\n", f)
	fmt.Printf("f=%+v\n", m)
	fmt.Printf("f=%#v\n", m)

	// 9. 转换
	y := 10
	z := "123"

	fmt.Println(strconv.Atoi(z))
	fmt.Println(strconv.Itoa(y))

}
