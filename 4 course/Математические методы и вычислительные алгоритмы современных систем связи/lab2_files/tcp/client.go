package main

import (
	"fmt"
	"io"
	"log"
	"net"
	"os"
	"strconv"
	"strings"
)

func client() {
	connection, err := net.Dial("tcp", "localhost:27001")
	if err != nil {
		panic(err)
	}
	defer connection.Close()
	fmt.Println("Connected to server, start receiving the file name and file size")
	bufferFileName := make([]byte, 64)
	bufferFileSize := make([]byte, 10)

	_, err = connection.Read(bufferFileSize)
	if err != nil {
		log.Println(err)
		return
	}
	fileSize, err := strconv.ParseInt(strings.Trim(string(bufferFileSize), ":"), 10, 64)
	if err != nil {
		log.Println(err)
		return
	}

	_, err = connection.Read(bufferFileName)
	if err != nil {
		log.Println(err)
		return
	}
	fileName := strings.Trim(string(bufferFileName), ":")

	newFile, err := os.Create("скачали_" + fileName)

	if err != nil {
		log.Println(err)
		os.Exit(-1)
	}
	defer func(newFile *os.File) {
		err := newFile.Close()
		if err != nil {
			log.Println(err)
		}
	}(newFile)
	var receivedBytes int64

	for {
		if (fileSize - receivedBytes) < BUFFERSIZE {
			_, err := io.CopyN(newFile, connection, fileSize-receivedBytes)
			if err != nil {
				log.Println(err)
				return
			}
			_, err2 := connection.Read(make([]byte, (receivedBytes+BUFFERSIZE)-fileSize))
			if err2 != nil {
				log.Println(err2)
				return
			}
			break
		}
		_, err3 := io.CopyN(newFile, connection, BUFFERSIZE)
		if err3 != nil {
			log.Println(err3)
			return
		}
		receivedBytes += BUFFERSIZE
	}
	fmt.Println("Received file completely!")
}

//	"bytes"
//	"fmt"
//	"io/ioutil"
//	"math/rand"
//	"net/http"
//	"strings"
//	"time"
//) ''
//
//func main() {
//	// your code here
//	response, err := http.Get("http://127.0.0.1:8080/api")
//	if err != nil {
//		fmt.Println(err)
//	}
//
//	body, err := ioutil.ReadAll(response.Body)
//	if err != nil {
//		fmt.Println(err)
//	}
//
//	strBody := string(body)
//
//	if strings.Contains(strBody, "Name") && strings.Contains(strBody, "Status") && strings.Contains(strBody, "Age") {
//		// your code here
//		_, err := http.Post("http://127.0.0.1:8080/api", "", bytes.NewBuffer(body))
//		if err != nil {
//			fmt.Println(err)
//		}
//	} else {
//		_, err := http.Post("http://127.0.0.1:8080/api", "", bytes.NewBuffer([]byte("invalid")))
//		if err != nil {
//			fmt.Println(err)
//		}
//	}
//	response.Body.Close()
//}
//
////::footer
//func init() {
//	var variants = []string{"Name:Mike, Age:20, Status:User", "Age:20, Status:User", "Age:20", "123"}
//	var val int
//	go func() {
//		http.HandleFunc("/api", func(w http.ResponseWriter, r *http.Request) {
//			if r.Method == "GET" {
//				rand.Seed(time.Now().UnixNano())
//				time.Sleep(100 * time.Millisecond)
//				val = rand.Intn(len(variants) - 1)
//				value := variants[val]
//				w.WriteHeader(http.StatusOK)
//				fmt.Fprintf(w, value)
//			} else if r.Method == "POST" {
//				read, err := ioutil.ReadAll(r.Body)
//				if err != nil {
//					fmt.Println(err)
//				}
//				if val == 0 && string(read) == variants[0] {
//					fmt.Println("valid")
//				} else if val != 0 && string(read) == "invalid" {
//					fmt.Println("valid")
//				} else {
//					fmt.Println("invalid")
//				}
//				w.WriteHeader(http.StatusOK)
//			}
//		})
//		http.ListenAndServe(":8080", nil)
//	}()
//	time.Sleep(500 * time.Millisecond)
//}
