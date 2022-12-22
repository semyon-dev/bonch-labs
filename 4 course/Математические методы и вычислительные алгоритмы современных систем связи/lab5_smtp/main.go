package main

import (
	"bytes"
	"encoding/base64"
	"fmt"
	"log"
	"net/smtp"
	"os"
)

var (
	host       = "smtp.gmail.com"
	username   = ""
	password   = ""
	portNumber = "587"
	to         = "" // получатель
	subject    = "ТЕМА ПИСЬМА"
)

func main() {

	var buf bytes.Buffer

	buf.WriteString(fmt.Sprintf("From: %s\r\n", username))
	buf.WriteString(fmt.Sprintf("To: %s\r\n", []string{to}))
	buf.WriteString(fmt.Sprintf("Subject: %s\r\n", subject))

	boundary := "my-boundary-779"
	buf.WriteString("MIME-Version: 1.0\r\n")
	buf.WriteString(fmt.Sprintf("Content-Type: multipart/mixed; boundary=%s\n",
		boundary))

	buf.WriteString(fmt.Sprintf("\r\n--%s\r\n", boundary))
	buf.WriteString("Content-Type: text/plain; charset=\"utf-8\"\r\n")
	buf.WriteString(fmt.Sprintf("\r\n%s", "ТЕЛО")) // тело сообщения

	buf.WriteString(fmt.Sprintf("\r\n--%s\r\n", boundary))
	buf.WriteString("Content-Type: image/jpeg; charset=\"utf-8\"\r\n")
	buf.WriteString("Content-Transfer-Encoding: base64\r\n")
	buf.WriteString("Content-Disposition: attachment; filename=upload.jpg\r\n")
	buf.WriteString("Content-ID: <upload.jpg>\r\n\r\n")

	data, err := os.ReadFile("upload.jpg")
	if err != nil {
		log.Println(err)
	}

	b := make([]byte, base64.StdEncoding.EncodedLen(len(data)))
	base64.StdEncoding.Encode(b, data)
	buf.Write(b)
	buf.WriteString(fmt.Sprintf("\r\n--%s", boundary))

	buf.WriteString("--")

	to := []string{to}

	auth := smtp.PlainAuth("", username, password, host)
	err = smtp.SendMail(fmt.Sprintf("%s:%s", host, portNumber), auth, username, to, buf.Bytes())
	if err != nil {
		log.Println(err)
	}
}
