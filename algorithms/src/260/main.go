package main

import "fmt"

// Given an array of numbers nums, in which exactly two elements appear only once and all
// the other elements appear exactly twice. Find the two elements that appear only once.
//
// For example:
//
// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
//
// Note:
// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only
// constant space complexity?

// first hash
func singleNumber(nums []int) []int {
	record := make(map[int]int)
	var res = make([]int, 0, 2)

	for _, v := range nums {
		record[v]++
	}
	for k, v := range record {
		if v == 1 {
			res = append(res, k)
		}
	}
	return res
}

// impressive !!
func singleNumber2(nums []int) []int {
	var xor int
	var res = make([]int, 2)
	for _, v := range nums {
		xor ^= v
	}
	// find the lowest bits which is different between two elements
	xor &= -xor
	for _, v := range nums {
		if xor&v > 0 {
			res[0] ^= v
		} else {
			res[1] ^= v
		}
	}
	return res
}

func main() {
	nums := []int{1, 2, 1, 3, 2, 5}
	fmt.Println(singleNumber(nums))
	fmt.Println(singleNumber2(nums))
}
