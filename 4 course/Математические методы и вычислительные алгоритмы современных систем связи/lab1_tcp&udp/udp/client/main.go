package main

import (
	"bufio"
	"fmt"
	"log"
	"net"
	"os"
	"strings"
)

func main() {

	s, err := net.ResolveUDPAddr("udp4", "127.0.0.1:8082")
	c, err := net.DialUDP("udp4", nil, s)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Printf("UDP сервер is %s\n", c.RemoteAddr().String())
	defer c.Close()

	for {
		reader := bufio.NewReader(os.Stdin)
		fmt.Print(">> ")
		text, _ := reader.ReadString('\n')
		_, err = c.Write([]byte(text))
		if strings.TrimSpace(text) == "STOP" {
			fmt.Println("Exiting UDP client!")
			return
		}

		if err != nil {
			log.Println(err)
			return
		}

		buffer := make([]byte, 1024)
		n, _, err := c.ReadFromUDP(buffer)
		if err != nil {
			fmt.Println(err)
			return
		}
		fmt.Printf("Ответ: %s\n", string(buffer[0:n]))
	}
}
