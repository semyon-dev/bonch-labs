package main

import (
	"fmt"
	"log"
	"net"
	"os"
)

func client() {

	// Open the file
	file, err := os.Open("upload.png")
	if err != nil {
		fmt.Println("Error opening file:", err)
		os.Exit(1)
	}
	defer file.Close()

	// Create a UDP connection
	conn, err := net.Dial("udp", "localhost:8888")
	if err != nil {
		fmt.Println("Error dialing:", err)
		os.Exit(1)
	}
	defer conn.Close()

	// Read the file and send it over the connection
	buf := make([]byte, 8192)
	for {
		// Read a chunk of the file
		n, err := file.Read(buf)
		if err != nil {
			log.Println(err)
			break
		}

		// Send the chunk over the connection
		_, err = conn.Write(buf[:n])
		if err != nil {
			fmt.Println("Error sending data:", err)
			break
		}
	}
}
