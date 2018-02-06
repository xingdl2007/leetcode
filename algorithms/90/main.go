package main

import (
	"sort"
	"fmt"
)

// Given a collection of integers that might contain duplicates nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// For example,
// If nums = [1,2,2], a solution is:
//
// [
//  [2],
//  [1],
//  [1,2,2],
//  [2,2],
//  [1,2],
//  []
// ]

// iterative solution, easy to catch the point
func subsetsWithDup(nums []int) [][]int {
	sort.Ints(nums)
	var res = [][]int{{}} // [] empty
	for i := 0; i < len(nums); {
		var dupCnt = 1
		for j := i + 1; j < len(nums); j++ {
			if nums[j] == nums[i] {
				dupCnt++
			} else {
				break
			}
		}
		for _, s := range res {
			tmp := make([]int, len(s), len(s))
			copy(tmp, s)
			for j := 1; j <= dupCnt; j++ {
				tmp = append(tmp, nums[i])
				res = append(res, tmp)
			}
		}
		i += dupCnt
	}
	return res
}

func main() {
	fmt.Println(subsetsWithDup([]int{1}))
	fmt.Println(subsetsWithDup([]int{1, 2}))
	fmt.Println(subsetsWithDup([]int{1, 2, 3}))
	fmt.Println(subsetsWithDup([]int{}))
	fmt.Println(subsetsWithDup([]int{1, 2, 2}))
}
