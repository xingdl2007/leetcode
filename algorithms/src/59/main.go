package main

import "fmt"

// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

// For example,
// Given n = 3,
//
// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

func generateMatrix(n int) [][]int {
	if n == 0 {
		return nil
	}
	var res = make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = make([]int, n)
	}
	r1, r2 := 0, n-1
	c1, c2 := 0, n-1
	for i := 1; r1 <= r2 && c1 <= c2; {
		for c := c1; c <= c2; c++ {
			res[r1][c] = i
			i++
		}
		for r := r1 + 1; r <= r2; r++ {
			res[r][c2] = i
			i++
		}
		for c := c2 - 1; c >= c1; c-- {
			res[r2][c] = i
			i++
		}
		for r := r2 - 1; r >= r1+1; r-- {
			res[r][c1] = i
			i++
		}
		r1++
		r2--
		c1++
		c2--
	}
	return res
}

func main() {
	for i := 0; i < 10; i++ {
		for _, l := range generateMatrix(i) {
			fmt.Println(l)
		}
		fmt.Println()
	}

}
