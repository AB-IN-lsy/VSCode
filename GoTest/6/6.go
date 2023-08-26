/*
 * @Author: NEFU AB-IN
 * @Date: 2023-08-23 22:36:26
 * @FilePath: \GoTest\6\6.go
 * @LastEditTime: 2023-08-23 22:48:50
 */
package main

import (
	"bufio"
	"log"
	"net"
)

// TCP echo server

func main() {
	server, err := net.Listen("tcp", "127.0.0.1:1080") // 监听端口，返回一个server
	if err != nil {
		panic(err)
	}
	for {
		client, err := server.Accept() // 在死循环里，用这个方法接收一个请求
		if err != nil {
			log.Printf("Accept failed %v", err)
			continue
		}
		go process(client) // 处理这个链接 go关键字 启动子线程去处理
		// 如果接受连接时出现错误，服务器会记录错误信息，然后继续等待下一个客户端连接
		// 否则为每个客户端连接启动一个独立的process协程来处理客户端请求，这样可以并发处理多个客户端连接。
	}
}

func process(conn net.Conn) {
	defer conn.Close()              // 最后将连接关掉
	reader := bufio.NewReader(conn) // 基于这个链接，创造一个只读的带缓冲的流
	for {
		b, err := reader.ReadByte() // 每次读一个字节
		if err != nil {
			break
		}
		_, err = conn.Write([]byte{b}) // 将读取的字节回显给客户端，直接写回到连接中
		if err != nil {
			break
		}
	}
}
