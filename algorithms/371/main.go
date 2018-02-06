package main

import "fmt"

// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
//
// Example:
// Given a = 1 and b = 2, return 3.
func getSum(a int, b int) int {
	x, y := a|b, a&b
	for y != 0 {
		x &^= y     // clear x
		y <<= 1     // right shift y
		yy := x & y // record new y: bits will not added in this cycle
		x |= y      // add
		y = yy      // update y
	}
	return x
}

// another, more easy to understand
func getSum2(a int, b int) int {
	if a == 0 {
		return b
	}
	for b != 0 {
		a, b = a^b, (a&b)<<1
	}
	return a
}

func main() {
	fmt.Println(getSum(1, 2))
}
