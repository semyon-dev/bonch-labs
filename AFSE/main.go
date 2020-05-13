package main

import (
	"errors"
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
func fp1(x float64) float64 {
	return 3*a*math.Pow(x, 2) + 2*b*x + c
}

// производная от уравнения
func fp2(x float64) float64 {
	return 6*a*x + 2*b
}

func main() {
	fmt.Println("------------------------------------------------------")
	fmt.Println("Выберите метод решения:")
	fmt.Println("1 - метод секущих")
	fmt.Println("2 - метод касательных")
	fmt.Println("3 - метод комбинированный метод хорд и касательных")
	fmt.Println("------------------------------------------------------")
	var method int
	_, err := fmt.Scan(&method)
	checkErr(err, "Ошибка при вводе метода!")
	fmt.Println("Введите a,b,c,d")
	_, err = fmt.Scan(&a, &b, &c, &d)
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
		checkErr(errors.New("Неверно указан интервал поиска"), "")
	}
	fmt.Println("Введите значение погрешности")
	_, err = fmt.Scan(&E)
	checkErr(err, "Неправильный формат погрешности!")
	if E < 0 {
		checkErr(errors.New("Значение погрешности должно быть положительным!"), "")
	}

	switch method {
	case 1:
		secant() // метод секущих
	case 2:
		tangents() // метод касательныx
	case 3:
		compatible()
	default:
		fmt.Println("Такого метода нет!")
	}
}

// метод касательных (Ньютона)
func tangents() {
	x0 := x
	x = b1
	f0 := f(x0)
	x := x0
	for math.Abs(f(x)) > E {
		x -= f0 / fp1(x)
		f0 = f(x)
	}
	fmt.Println("Ответ: ", x)
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

// метод комбинированный метод хорд и касательных
func compatible() float64 { // функция вычисляет по методу хорд и касательных
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
	fmt.Println("Ответ:", (a+b)/2.0)
	return (a + b) / 2.0
}

func checkErr(err error, toPrint string) {
	if err != nil {
		fmt.Println(toPrint, err)
		os.Exit(0)
	}
}
