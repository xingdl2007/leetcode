package main

import (
	"math"
	"fmt"
)

// Given a non-empty array of integers, return the third maximum number in this array.
// If it does not exist, return the maximum number. The time complexity must be in O(n).

// Example 1:
// Input: [3, 2, 1]
//
// Output: 1
//
// Explanation: The third maximum is 1.
// Example 2:
// Input: [1, 2]
//
// Output: 2
//
// Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
// Example 3:
// Input: [2, 2, 3, 1]
//
// Output: 1
//
// Explanation: Note that the third maximum here means the third maximum distinct number.
// Both numbers with value 2 are both considered as second maximum.

// not very safe, if math.MinInt64 is valid
func thirdMax(nums []int) int {
	first, second, third := math.MinInt64, math.MinInt64, math.MinInt64
	for _, v := range nums {
		if v > first {
			second, third = first, second
			first = v
		} else if v > second {
			if v != first {
				third = second
				second = v
			}
		} else if v >= third {
			if v != second {
				third = v
			}
		}
	}
	if third == math.MinInt64 {
		return first
	}
	return third
}

func main() {
	fmt.Println(thirdMax([]int{3, 2, 1}))
	fmt.Println(thirdMax([]int{1, 2}))
	fmt.Println(thirdMax([]int{2, 2, 3, 1}))
	fmt.Println(thirdMax([]int{1, 2, 2, 5, 3, 5}))
	fmt.Println(thirdMax([]int{1, 2, -2147483648}))
	fmt.Println(thirdMax([]int{1, 1, -2147483648}))
}
