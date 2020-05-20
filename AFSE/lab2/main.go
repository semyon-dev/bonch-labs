package main

import (
	"errors"
	"fmt"
	"math"
	"os"
)

var a, b, c, d float64
var a1, b1 float64

var E = 0.01 // погрешность

// уравнение
func f(x float64) float64 {
	return a*math.Pow(x, 3) + b*math.Pow(x, 2) + c*x + d
}

// производная от уравнения
func fp1(x float64) float64 {
	return 3*a*math.Pow(x, 2) + 2*b*x + c
}

// производная от уравнения
func fp2(x float64) float64 {
	return 6*a*x + 2*b
}

func main() {

	fmt.Println("------------------------------------------------------")
	fmt.Println("1 - метод секущих")
	fmt.Println("2 - метод касательных")
	fmt.Println("3 - метод комбинированный метод хорд и касательных")
	fmt.Println("------------------------------------------------------")
	fmt.Println("Введите a,b,c,d")
	_, err := fmt.Scan(&a, &b, &c, &d)
	checkErr(err, "Неправильный формат данных!")
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
	_, err = fmt.Scan(&a1, &b1)
	checkErr(err, "Неправильный формат отрезка!")
	if a1 > b1 {
		checkErr(errors.New("неверно указан интервал поиска"), "")
	}
	fmt.Println("Введите значение погрешности")
	_, err = fmt.Scan(&E)
	checkErr(err, "Неправильный формат погрешности!")
	if E < 0 {
		checkErr(errors.New("значение погрешности должно быть положительным"), "")
	}

	chan1 := make(chan float64, 3)

	go secant(chan1) // метод секущих
	fmt.Println("метод секущих: ", <-chan1)
	go tangents(chan1) // метод касательныx
	fmt.Println("метод касательныx: ", <-chan1)
	go compatible(chan1) // комбинированный метод
	fmt.Println("комбинированный метод: ", <-chan1)
}

// метод касательных (Ньютона)
func tangents(c chan float64) {
	var x float64
	x0 := x
	f0 := f(x0)
	x = x0
	for math.Abs(f(x)) > E {
		x -= f0 / fp1(x)
		f0 = f(x)
	}
	c <- x
	fmt.Println("метод касательных выполнился")
}

// метод секущих
func secant(c chan float64) {
	var y, xN float64
	var n = 0
	var a11 = a1
	var b11 = b1
	for {
		n++
		y = xN
		xN = b11 - ((b11-a11)/(f(b11)-f(a11)))*f(b11)
		a11 = b11
		b11 = xN
		if !(math.Abs(y-xN) >= E) {
			break
		}
	}
	if math.IsNaN(xN) {
		fmt.Println("Не получилось посчитать, возможно мы вышли за допустимые пределы")
	}
	c <- xN
	fmt.Println("метод секущих выполнился")
}

// метод комбинированный метод хорд и касательных
func compatible(c chan float64) { // функция вычисляет по методу хорд и касательных
	var a, b float64
	a = a1
	b = b1
	var k int
	for ; math.Abs(b-a) > E*2; { //Построение хорд и касательных продолжается до достижения необходимой точности решения е
		if f(a)*fp2(a) < 0 {
			a += (b - a) / (f(a) - f(b)) * f(a)
		} else {
			a -= f(a) / fp1(a)
		}
		if f(b)*fp2(b) < 0 {
			b += (a - b) / (f(b) - f(a)) * f(b)
		} else {
			b -= f(b) / fp1(b)
		}
		k++
	}
	c <- (a + b) / 2.0
	fmt.Println("метод комбинированный выполнился")
}

func checkErr(err error, toPrint string) {
	if err != nil {
		fmt.Println(toPrint, err)
		os.Exit(0)
	}
}
