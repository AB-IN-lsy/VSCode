/*
 * @Author: NEFU AB-IN
 * @Date: 2023-08-24 16:20:21
 * @FilePath: \GoTest\12\12_test.go
 * @LastEditTime: 2023-08-24 16:25:21
 */
package main

import (
	"testing"
)

func Add(a int, b int) int {
	return a + b
}

func TestAdd(t *testing.T) {
	output := Add(1, 2)
	expectOutput := 3
	if output != expectOutput {
		t.Error("Add failed")
	}
}
