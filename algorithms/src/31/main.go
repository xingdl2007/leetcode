package main

import (
	"sort"
	"fmt"
)

// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
// The replacement must be in-place, do not allocate extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

func nextPermutation(nums []int) {
	var pos = -1
	for i := len(nums) - 1; i > 0; i-- {
		if nums[i] > nums[i-1] {
			pos = i
			break
		}
	}
	// sort ascending
	if pos == -1 {
		sort.Ints(nums)
	} else {
		sort.Ints(nums[pos:])
		for i := pos; i < len(nums); i++ {
			if nums[i] > nums[pos-1] {
				nums[pos-1], nums[i] = nums[i], nums[pos-1]
				return
			}
		}
	}
}

func main() {
	a := []int{1, 2, 3}
	nextPermutation(a)
	fmt.Println(a)

	a = []int{3, 2, 1}
	nextPermutation(a)
	fmt.Println(a)

	a = []int{1, 1, 5}
	nextPermutation(a)
	fmt.Println(a)

	a = []int{}
	nextPermutation(a)
	fmt.Println(a)
}
