package main

import (
	"fmt"
	"time"
)

func main() {
	var n, c int
	a := 1
	b := 0
	fmt.Printf("请问你想看到斐波那契数列的第几项: ")
	fmt.Scanf("%d", &n)
	start := time.Now()
	for i := 1; i <= n; i++ {
		fmt.Printf("F[%d] = %d\n", i, a)
		b, c = a, b
		a += c
	}
	end := time.Now()
	fmt.Printf("耗时: %dms\n", end.Sub(start).Milliseconds())
}

