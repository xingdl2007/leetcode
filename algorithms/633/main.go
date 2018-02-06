package main

import (
	"fmt"
	"math"
)

// Given a non-negative integer c, your task is to decide whether there're two
// integers a and b such that a*a+ b*b = c.
//
// Example 1:
// Input: 5
// Output: True
//
// Explanation: 1 * 1 + 2 * 2 = 5
//
// Example 2:
// Input: 3
// Output: False

// Oops: Time Limit Exceeded
func judgeSquareSum(c int) bool {
	root := int(math.Sqrt(float64(c)))

	// this part?
	for i := 0; i <= root; i++ {
		for j := i; j <= root; j++ {
			if i*i+j*j == c {
				return true
			}
		}
	}
	return false
}

// have better method?
func judgeSquareSum2(c int) bool {
	if c < 0 {
		return false
	}
	root := int(math.Sqrt(float64(c)))
	low, high := 0, root
	for low <= high {
		cur := low*low + high*high
		if cur < c {
			low++
		} else if cur > c {
			high--
		} else {
			return true
		}
	}
	return false
}

func main() {
	fmt.Println(judgeSquareSum2(5))
	fmt.Println(judgeSquareSum2(2))
	fmt.Println(judgeSquareSum2(3))
	fmt.Println(judgeSquareSum2(4))
	fmt.Println(judgeSquareSum2(8))
}
