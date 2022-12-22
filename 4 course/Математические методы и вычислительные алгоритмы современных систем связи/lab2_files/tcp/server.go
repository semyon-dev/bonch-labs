package main

import (
	"fmt"
	"io"
	"log"
	"net"
	"os"
	"strconv"
)

const BUFFERSIZE = 1024
const FILE = "upload.jpg"

func main() {
	server, err := net.Listen("tcp", "localhost:27001")
	if err != nil {
		fmt.Println("Error listetning: ", err)
		os.Exit(1)
	}
	defer server.Close()
	fmt.Println("Server started! Waiting for connections...")

	go client()
	for {
		connection, err := server.Accept()
		if err != nil {
			fmt.Println("Error: ", err)
			os.Exit(1)
		}
		fmt.Println("Client connected")
		go sendFileToClient(connection)
	}
}

func sendFileToClient(connection net.Conn) {
	fmt.Println("A client has connected!")
	defer connection.Close()
	file, err := os.Open(FILE)
	if err != nil {
		fmt.Println(err)
		return
	}
	fileInfo, err := file.Stat()
	if err != nil {
		fmt.Println(err)
		return
	}
	fileSize := fillString(strconv.FormatInt(fileInfo.Size(), 10), 10)
	fileName := fillString(fileInfo.Name(), 64)
	fmt.Println("Sending filename and filesize!")
	_, err = connection.Write([]byte(fileSize))
	if err != nil {
		log.Println(err)
		return
	}
	_, err = connection.Write([]byte(fileName))
	if err != nil {
		return
	}
	if err != nil {
		log.Println(err)
		return
	}
	sendBuffer := make([]byte, BUFFERSIZE)
	fmt.Println("Start sending file!")
	for {
		_, err = file.Read(sendBuffer)
		if err == io.EOF {
			break
		}
		_, err := connection.Write(sendBuffer)
		if err != nil {
			log.Println(err)
			return
		}
	}
	fmt.Println("File has been sent, closing connection!")
	return
}

func fillString(retunString string, toLength int) string {
	for {
		lengtString := len(retunString)
		if lengtString < toLength {
			retunString = retunString + ":"
			continue
		}
		break
	}
	return retunString
}
