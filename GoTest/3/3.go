package main

import (
	"fmt"
	"time"
)

func main() {
	now := time.Now() //获取当前时间
	fmt.Printf("current time:%v\n", now)
	year := now.Year()     //年
	month := now.Month()   //月
	day := now.Day()       //日
	hour := now.Hour()     //小时
	minute := now.Minute() //分钟
	second := now.Second() //秒
	fmt.Printf("%d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second)

	now1 := time.Now()            //获取当前时间
	timestamp1 := now1.Unix()     //时间戳
	timestamp2 := now1.UnixNano() //纳秒时间戳
	later := now1.Add(time.Hour)  // 当前时间加1小时后的时间
	fmt.Printf("现在的时间戳：%v\n", timestamp1)
	fmt.Printf("现在的纳秒时间戳：%v\n", timestamp2)
	fmt.Println(later)
}
