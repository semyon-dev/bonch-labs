package main

import (
	"log"
	"net"
)
import "fmt"
import "bufio"
import "strings" // требуется только ниже для обработки примера

func main() {

	fmt.Println("Launching server...")

	// Устанавливаем прослушивание порта
	listener, err := net.Listen("tcp", ":8081")
	if err != nil {
		log.Println(err)
	}

	// Открываем порт
	conn, _ := listener.Accept()

	// Запускаем цикл
	for {
		// Будем прослушивать все сообщения разделенные \n
		message, _ := bufio.NewReader(conn).ReadString('\n')
		// Распечатываем полученое сообщение
		fmt.Print("Message Received:", message)
		// Процесс выборки для полученной строки
		newmessage := strings.ToUpper(message)
		// Отправить новую строку обратно клиенту
		conn.Write([]byte(newmessage + "\n"))
	}
}
