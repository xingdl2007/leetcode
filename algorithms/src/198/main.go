package main

import "fmt"

// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed, the only constraint stopping you from
// robbing each of them is that adjacent houses have security system connected and it will
// automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each house,
// determine the maximum amount of money you can rob tonight without alerting the police.

// classic dynamic programming
func rob(nums []int) int {
	var a, b int
	for _, n := range nums {
		a, b = b, max(n+a, b)
	}
	return b
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// ref: ???
func rob2(nums []int) int {
	var preNo, preYes int
	for _, v := range nums {
		preNo, preYes = max(preYes, preNo), preNo+v
	}
	return max(preYes, preNo)
}

func main() {
	fmt.Println(rob([]int{1, 2, 3, 4, 5, 6, 7, 8, 9}))
	fmt.Println(rob([]int{}))
	fmt.Println(rob([]int{1}))
	fmt.Println(rob([]int{1, 1}))

	fmt.Println()
	fmt.Println(rob2([]int{1, 2, 3, 4, 5, 6, 7, 8, 9}))
	fmt.Println(rob2([]int{}))
	fmt.Println(rob2([]int{1}))
	fmt.Println(rob2([]int{1, 1}))
}
