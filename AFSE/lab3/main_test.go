package main

import (
	"fmt"
	"math"
	"testing"
)

var a float64 = 1
var b float64 = 3
var c float64 = 12
var d float64 = 8
var a1 float64 = -5
var b1 float64 = 5

var E = 0.01 // погрешность

// уравнение
func f(x float64) float64 {
	return a*math.Pow(x, 3) + b*math.Pow(x, 2) + c*x + d
}

// производная от уравнения
func fp1(x float64) float64 {
	return 3*a*math.Pow(x, 2) + 2*b*x + c
}

// производная от производной
func fp2(x float64) float64 {
	return 6*a*x + 2*b
}

// метод касательных (Ньютона)
func BenchmarkTangents(b *testing.B) {
	for i := 0; i < b.N; i++ {
		var x float64
		x0 := x
		f0 := f(x0)
		x = x0
		for math.Abs(f(x)) > E {
			x -= f0 / fp1(x)
			f0 = f(x)
		}
	}
}

// метод секущих
func BenchmarkSecant(b *testing.B) {
	for i := 0; i < b.N; i++ {
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
	}
}

// метод комбинированный метод хорд и касательных
func BenchmarkCompatible(b *testing.B) { // функция вычисляет по методу хорд и касательных
	for i := 0; i < b.N; i++ {
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
		_ = (a + b) / 2.0
	}
}
