package main

import "fmt"

// Given an array of integers nums, write a method that returns the "pivot" index of this array.
//
// We define the pivot index as the index where the sum of the numbers to the left of the index
// is equal to the sum of the numbers to the right of the index.
//
// If no such index exists, we should return -1. If there are multiple pivot indexes,
// you should return the left-most pivot index.
//
// Example 1:
// Input:
// nums = [1, 7, 3, 6, 5, 6]
//
// Output: 3
//
// Explanation:
// The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
// Also, 3 is the first index where this occurs.
//
// Example 2:
// Input:
// nums = [1, 2, 3]
//
// Output: -1
//
// Explanation:
// There is no index that satisfies the conditions in the problem statement.
// Note:
//
// The length of nums will be in the range [0, 10000].
// Each element nums[i] will be an integer in the range [-1000, 1000].

// Math method, two passes
// shit: negative numbers, and left or right part may be empty
// Runtime: 39 ms, 96.55%
func pivotIndex(nums []int) int {
	var sum int
	for _, n := range nums {
		sum += n
	}
	var left int
	for i, n := range nums {
		if left == (sum - nums[i] - left) {
			return i
		}
		left += n
	}
	return -1
}

func main() {
	fmt.Println(pivotIndex([]int{1, 2, 3}))
	fmt.Println(pivotIndex([]int{1, 7, 3, 6, 5, 6}))
	fmt.Println(pivotIndex([]int{}))
	fmt.Println(pivotIndex([]int{6, 4, 1, 9}))
	fmt.Println(pivotIndex([]int{1, 1}))
	fmt.Println(pivotIndex([]int{1}))
	fmt.Println(pivotIndex([]int{1, 1, 1}))
	fmt.Println(pivotIndex([]int{-1, -1, -1, -1, -1, 0}))
	fmt.Println(pivotIndex([]int{-1, -1, -1, 0, 1, 1}))
}
