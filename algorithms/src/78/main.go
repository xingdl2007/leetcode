package main

import "fmt"

// Given a set of distinct integers, nums, return all possible subsets (the power set).
// Note: The solution set must not contain duplicate subsets.
//
// For example,
// If nums = [1,2,3], a solution is:
//
// [
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
// ]

// Runtime: 6 ms, 58.06%
func subsets(nums []int) [][]int {
	if len(nums) == 0 {
		return [][]int{make([]int, 0)}
	}
	var left [][]int
	ret := subsets(nums[:len(nums)-1])
	for _, sub := range ret {
		tmp := make([]int, len(sub), len(sub)+1)
		copy(tmp, sub)
		tmp = append(tmp, nums[len(nums)-1])

		left = append(left, tmp)
	}
	ret = append(ret, left...)
	return ret
}

func main() {
	fmt.Println(subsets([]int{1}))
	fmt.Println(subsets([]int{1, 2}))
	fmt.Println(subsets([]int{1, 2, 3}))
	fmt.Println(subsets([]int{}))
}
