/*
 * @Author: NEFU AB-IN
 * @Date: 2023-08-06 23:17:06
 * @FilePath: \GoTest\2\2.go
 * @LastEditTime: 2023-08-22 11:42:20
 */
package main

import (
	"encoding/json"
	"fmt"
)

type Student struct {
	Name string `json:"name"`
	Sid  string `json:"sid"`
}

func main() {
	s := Student{Name: "jonh", Sid: "10323"}
	//序列化
	p, err := json.Marshal(s)
	if err != nil {
		panic(err)
	}
	fmt.Println(p)

	//反序列化
	err = json.Unmarshal(p, &s)
	if err != nil {
		panic(err)
	}
	fmt.Printf("%#v\n", s)
}
