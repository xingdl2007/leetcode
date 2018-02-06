package main

import (
	"sort"
	"fmt"
)

// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// For example,
// [1,1,2] have the following unique permutations:
//
// [
//  [1,1,2],
//  [1,2,1],
//  [2,1,1]
// ]

// lexicographic works, amazing property !!!
func permuteUnique(nums []int) [][]int {
	n := len(nums)
	var ans [][]int
	sort.Ints(nums)

	for {
		tmp := make([]int, n)
		copy(tmp, nums)
		ans = append(ans, tmp)

		pos := -1
		for i := n - 1; i > 0; i-- {
			if nums[i] > nums[i-1] {
				pos = i
				break
			}
		}
		if pos == -1 {
			break
		}

		sort.Ints(nums[pos:])
		// swap with the smallest one which is bigger than nums[pos]
		for i := pos; i < n; i++ {
			if nums[i] > nums[pos-1] {
				nums[i], nums[pos-1] = nums[pos-1], nums[i]
				break
			}
		}
	}
	return ans
}

func main() {
	fmt.Println(permuteUnique([]int{1, 1, 2}))
}
