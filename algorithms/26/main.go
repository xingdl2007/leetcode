package main

import (
	"fmt"
)

// Given a sorted array, remove the duplicates in place such that each element
// appear only once and return the new length.
//
// Do not allocate extra space for another array, you must do this in place with constant memory.
//
// For example,
// Given input array nums = [1,1,2],
//
// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
// It doesn't matter what you leave beyond the new length.

// Runtime: 126 ms, 16.33%, shit!
func removeDuplicates(nums []int) int {
	var count int
	for i := len(nums) - 1; i >= 0; {
		var j int
		count++

		for j = i - 1; j >= 0 && nums[j] == nums[i]; j-- {
		}
		if j != i-1 {
			copy(nums[j+1:], nums[i:count+i])
		}
		i = j
	}
	return count
}

// avoid copy which may be expensive
// Runtime: 99 ms, 95%
func removeDuplicates2(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	idx := 1
	for i := 1; i < len(nums); i++ {
		if nums[i-1] == nums[i] {
			continue
		}
		nums[idx] = nums[i]
		idx++
	}
	return idx
}

func main() {
	s := []int{1, 1, 2, 3, 4, 5, 5, 5, 0, 7, 8, 9}
	fmt.Println(removeDuplicates2(s))
	fmt.Println(s)

	s = []int{1, 1}
	fmt.Println(removeDuplicates2(s))
	fmt.Println(s)
}
