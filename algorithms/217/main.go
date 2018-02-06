package main

import "fmt"

// Given an array of integers, find if the array contains any duplicates.
// Your function should return true if any value appears at least twice in the array,
// and it should return false if every element is distinct.

func containsDuplicate(nums []int) bool {
	m := make(map[int]bool)
	for _, n := range nums {
		if m[n] {
			return true
		}
		m[n] = true
	}
	return false
}

func main() {
	fmt.Println(containsDuplicate([]int{1, 2, 3, 4, 1}))
	fmt.Println(containsDuplicate([]int{1}))
}
