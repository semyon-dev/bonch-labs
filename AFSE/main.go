package main

import (
	"fmt"
	"math"
	"os"
)

var a, b, c, d float64
var a1, b1, x float64

var E = 0.01 // погрешность

// уравнение
func f(x float64) float64 {
	return a*math.Pow(x, 3) + b*math.Pow(x, 2) + c*x + d
}

// производная от уравнения
func fp(x float64) float64 {
	return 3*a*math.Pow(x, 2) + 2*b*x + c
}

func main() {
	fmt.Println("выберите метод решения")
	fmt.Println("метод секущих - 0")
	fmt.Println("метод касательных - 1")
	var method int
	fmt.Scan(&method)
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

	fmt.Println("Введите границы отрезка [a;b]")
	fmt.Scan(&a1, &b1)
	fmt.Println("Введите значение погрешности")
	fmt.Scan(&E)
	if a1 > b1 {
		fmt.Println("Неверно указан интервал поиска")
		os.Exit(0)
	}
	if E < 0 {
		fmt.Println("Значение погрешности должно быть положительным")
		os.Exit(0)
	}

	switch method {
	case 0:
		secant() // метод секущих
	case 1:
		tangents() // метод касательныx
	default:
		fmt.Println("Такого метода нет!")
	}
}

// метод касательных
func tangents() {
	x = b1
	fmt.Println("Корень функции: ", Newton(x, E))
}

func Newton(x0, epsilon float64) float64 {
	f0 := f(x0)
	x := x0
	for math.Abs(f(x)) > epsilon {
		x -= f0 / fp(x)
		f0 = f(x)
	}
	return x
}

// метод секущих
func secant() {
	var y, xN float64
	var n = 0
	for {
		n++
		y = xN
		xN = b1 - ((b1-a1)/(f(b1)-f(a1)))*f(b1)
		a1 = b1
		b1 = xN
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
