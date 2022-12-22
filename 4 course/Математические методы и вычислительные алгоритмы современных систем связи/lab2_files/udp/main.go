package main

import (
	"fmt"
	"net"
	"os"
)

func main() {
	// Bind to a port to listen for incoming connections
	addr, err := net.ResolveUDPAddr("udp", ":8888")
	if err != nil {
		fmt.Println("Error resolving UDP address:", err)
		return
	}
	conn, err := net.ListenUDP("udp", addr)
	if err != nil {
		fmt.Println("Error listening:", err)
		return
	}
	defer conn.Close()

	go client()

	// Create a buffer to store incoming data
	buf := make([]byte, 8192)

	// Read incoming data into the buffer
	n, _, err := conn.ReadFromUDP(buf)
	if err != nil {
		fmt.Println("Error reading from UDP:", err)
		return
	}

	// Create a file to store the incoming data
	file, err := os.Create("received_file.png")
	if err != nil {
		fmt.Println("Error creating file:", err)
		return
	}
	defer file.Close()

	// Write the incoming data to the file
	_, err = file.Write(buf[:n])
	if err != nil {
		fmt.Println("Error writing to file:", err)
		return
	}
}
