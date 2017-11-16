package main

import "fmt"

// Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
//
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// hash
func singleNumber(nums []int) int {
	record := make(map[int]int)
	for _, v := range nums {
		record[v]++
	}
	for v, c := range record {
		if c == 1 {
			return v
		}
	}
	return -1
}

// no extra memory?
// impressive !!
func singleNumber2(nums []int) int {
	a, b, c := 0, 0, 0
	for _, v := range nums {
		b |= a & v // each position bit 1 occurs two times
		a ^= v     // each position bit 1 occurs one time
		c = a & b  // each position bit 1 occurs three times

		a &^= c // clear bit position which 1 occurs three times
		b &^= c // clear bit position which 1 occurs three times
	}
	return a
}

// insight: impressive, thinking in bit level
func singleNumber3(nums []int) int {
	a, b := 0, 0
	for _, v := range nums {
		b = (b ^ v) &^ a
		a = (a ^ v) &^ b
	}
	return b
}

func main() {
	var array []int
	array = []int{2, 2, 2, 3}
	fmt.Println(singleNumber(array))
	fmt.Println(singleNumber2(array))
	fmt.Println(singleNumber3(array))

}
