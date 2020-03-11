package main

import (
	"fmt"
	"math"
	"os"
)

var a, b, c, d, x1, x2 float64

const E = 0.01 // погрешность

func f(x float64) float64 {
	return a*math.Pow(x, 3) + b*math.Pow(x, 2) + c*x + d
}

func main() {
	fmt.Println("Введите a,b,c,d")
	_, err := fmt.Scan(&a, &b, &c, &d)
	if err != nil {
		fmt.Println("Неправильный формат данных!")
		os.Exit(0)
	}
	if a == 0 && b == 0 && c == 0 {
		if d == 0 {
			fmt.Println("x - любое")
			os.Exit(0)
		} else if d != 0 {
			fmt.Println("нет решений")
			os.Exit(0)
		}
	}
	fmt.Println("Введите x1, x2") // начальное приближение x1, начальное приближение x2
	_, err = fmt.Scan(&x1, &x2)
	if err != nil {
		fmt.Println("Неправильный формат данных!")
		os.Exit(0)
	}
	var y, xN float64
	var n = 0
	for {
		n++
		y = xN
		xN = x2 - ((x2-x1)/(f(x2)-f(x1)))*f(x2)
		x1 = x2
		x2 = xN
		if !(math.Abs(y-xN) >= E) {
			break
		}
	}
	if math.IsNaN(xN) {
		fmt.Println("Не получилось посчитать, возможно мы вышли за допустимые пределы")
	} else {
		fmt.Println("Ответ:", xN)
		fmt.Println("Найден на итерации номер", n)
	}
}
