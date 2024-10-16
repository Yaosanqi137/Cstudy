package main

import (
	"fmt"
	"time"
)

func fibonacci(term int) int {
	if term <= 1 {
		return 1
	} else {
		return fibonacci(term-1) + fibonacci(term-2)
	}
}

func main() {
	var n int
	fmt.Printf("请问你想看到斐波那契数列的第几项: ")
	fmt.Scanf("%d", &n)
	start := time.Now()
	for i := 1; i <= n; i++ {
		fmt.Printf("F[%d] = %d\n", i, fibonacci(i))
	}
	end := time.Now()
	fmt.Printf("耗时: %dms\n", end.Sub(start).Milliseconds())
}

