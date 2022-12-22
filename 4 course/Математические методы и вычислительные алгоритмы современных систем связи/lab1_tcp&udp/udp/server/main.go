package main

import (
	"fmt"
	"net"
	"strings"
)

func main() {

	PORT := ":8082"

	s, err := net.ResolveUDPAddr("udp4", PORT)
	if err != nil {
		fmt.Println(err)
		return
	}

	connection, err := net.ListenUDP("udp4", s)
	if err != nil {
		fmt.Println(err)
		return
	}

	defer connection.Close()
	buffer := make([]byte, 1024)

	for {
		n, addr, err := connection.ReadFromUDP(buffer)
		fmt.Print("полученное сообщение -> ", string(buffer[0:n-1]))

		if strings.TrimSpace(string(buffer[0:n])) == "STOP" {
			fmt.Println("Exiting UDP server!")
			return
		}

		_, err = connection.WriteToUDP(buffer, addr)
		if err != nil {
			fmt.Println(err)
			return
		}
	}
}
