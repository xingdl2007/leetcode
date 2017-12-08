package main

import (
	"fmt"
	"sort"
)

// Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

// Example 1:
// Input: [1,4,3,2]
//
// Output: 4
// Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
// Note:
// n is a positive integer, which is in the range of [1, 10000].
// All the integers in the array will be in the range of [-10000, 10000].

func arrayPairSum(nums []int) int {
	sort.Ints(nums)
	var sum int
	for i := 0; i < len(nums)-1; i += 2 {
		sum += nums[i]
	}
	return sum
}

func main() {
	fmt.Println(arrayPairSum([]int{1, 4, 2, 3}))
	fmt.Println(arrayPairSum([]int{1, 1}))
	fmt.Println(arrayPairSum([]int{1, 1, 1, 1, 1, 1, 1, 1,}))
	fmt.Println(arrayPairSum([]int{1, 1, 4, 1, 5, 1, 1, 2,}))
}
