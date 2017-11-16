package main

import "fmt"

// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
// find the one that is missing from the array.
//
// For example,
// Given nums = [0, 1, 3] return 2.
//
// Note:
// Your algorithm should run in linear runtime complexity.
// Could you implement it using only constant extra space complexity?

// hash
func missingNumber(nums []int) int {
	record := make(map[int]struct{})
	for _, n := range nums {
		record[n] = struct{}{}
	}
	for i := 0; i <= len(nums); i++ {
		if _, ok := record[i]; !ok {
			return i
		}
	}
	return -1
}

// math, cheat
func missingNumber2(nums []int) int {
	n := len(nums)
	sum := n * (n + 1) / 2
	for _, v := range nums {
		sum -= v
	}
	return sum
}

// bit manipulation, impressive
func missingNumber3(nums []int) int {
	missing := len(nums)
	for i, v := range nums {
		missing ^= i ^ v
	}
	return missing
}

func main() {
	fmt.Println(missingNumber([]int{1, 0, 3}))
	fmt.Println(missingNumber([]int{1, 0, 3}))
	fmt.Println(missingNumber([]int{0}))

	fmt.Println(missingNumber2([]int{1, 0, 3}))
	fmt.Println(missingNumber2([]int{1, 0, 3}))
	fmt.Println(missingNumber2([]int{0}))

	fmt.Println(missingNumber3([]int{1, 0, 3}))
	fmt.Println(missingNumber3([]int{1, 0, 3}))
	fmt.Println(missingNumber3([]int{0}))
}
