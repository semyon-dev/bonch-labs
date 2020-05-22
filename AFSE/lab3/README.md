## Пример тестов + svg картинка профилирования

GOGC=off go test -bench=BenchmarkCompatible -cpuprofile cpuBenchmarkCompatible.out

go tool pprof -svg ./lab3_compatible.test ./cpuBenchmarkCompatible.out > compatible.svg
