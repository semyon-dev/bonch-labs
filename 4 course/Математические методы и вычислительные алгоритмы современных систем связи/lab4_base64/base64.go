package main

import (
	"encoding/base64"
	"fmt"
)

func main() {

	fmt.Println("исходная строка:")
	data := "привет"
	fmt.Println(data)

	sEnc := base64.StdEncoding.EncodeToString([]byte(data))

	fmt.Println("encode строка:")
	fmt.Println(sEnc)

	// Base64 Standard Decoding
	sDec, err := base64.StdEncoding.DecodeString(sEnc)
	if err != nil {
		fmt.Printf("Error decoding string: %s ", err.Error())
		return
	}

	fmt.Println("decode строка:")
	fmt.Println(string(sDec))
}
