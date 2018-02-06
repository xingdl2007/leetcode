package main

import "fmt"

// Given an array of integers, every element appears twice except for one. Find that single one.
//
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// hash
func singleNumber(nums []int) int {
	record := make(map[int]struct{})

	for _, v := range nums {
		if _, ok := record[v]; !ok {
			record[v] = struct{}{}
		} else {
			delete(record, v)
		}
	}

	for v := range record {
		return v
	}

	return -1
}

// XOR
func singleNumber2(nums []int) int {
	var ret int
	for _, v := range nums {
		ret ^= v
	}
	return ret
}

func main() {
	var array []int

	array = []int{1, 1, 2, 2, 4}
	fmt.Println(singleNumber2(array))
}
