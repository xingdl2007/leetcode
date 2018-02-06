package main

import (
	"fmt"
	"sort"
)

// Given an array S of n integers, are there elements a, b, c, and d in S such that
// a + b + c + d = target? Find all unique quadruplets in the array which gives the
// sum of target.

// Note: The solution set must not contain duplicate quadruplets.
//
// For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
// [-1,  0, 0, 1],
// [-2, -1, 1, 2],
// [-2,  0, 0, 2]
// ]

// Runtime: 42 ms, around 34.78%
// why not use threeSum? the already known solution?
// may be it not the best for this specific question, may be it has better solution
func fourSum(nums []int, target int) [][]int {
	var res [][]int
	sort.Ints(nums)

	for i := 0; i < len(nums); i++ {
		if i == 0 || (i > 0 && nums[i] != nums[i-1]) {
			tmp := threeSum(target-nums[i], nums[i+1:], nums[i])
			res = append(res, tmp...)
		}
	}
	return res
}

func threeSum(target int, nums []int, add int) [][]int {
	var ret [][]int
	for i := 0; i < len(nums)-2; i++ {
		if i == 0 || (i > 0 && nums[i] != nums[i-1]) {
			lo, hi, sum := i+1, len(nums)-1, target-nums[i]
			for lo < hi {
				if nums[lo]+nums[hi] < sum {
					lo++
				} else if nums[lo]+nums[hi] > sum {
					hi--
				} else {
					ret = append(ret, []int{nums[i], nums[lo], nums[hi], add})
					for lo < hi && nums[lo] == nums[lo+1] {
						lo++
					}
					for lo < hi && nums[hi] == nums[hi-1] {
						hi--
					}
					lo++
					hi--
				}
			}
		}
	}
	return ret
}

// same thought as threeSum, but eliminate unnecessary function call!!!
// Runtime: 19 ms, 84.78%
func fourSum2(nums []int, target int) [][]int {
	sort.Ints(nums)
	var res [][]int

	for i := 0; i < len(nums)-3; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i + 1; j < len(nums)-2; j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}
			for l, r := j+1, len(nums)-1; l < r; {
				sum := nums[i] + nums[j] + nums[l] + nums[r]
				if sum > target {
					r--
				} else if sum < target {
					l++
				} else {
					res = append(res, []int{nums[i], nums[j], nums[l], nums[r]})
					for ; l < r && nums[l] == nums[l+1]; l++ {
					}
					l++
					for ; l < r && nums[r] == nums[r-1]; r-- {
					}
					r--
				}
			}
		}
	}
	return res
}

func main() {
	fmt.Println(fourSum([]int{1, 0, -1, 0, -2, 2}, 0))

	//	fmt.Println([5,5,3,5,1,-5,1,-2])
	fmt.Println(fourSum([]int{5, 5, 3, 5, 1, -5, 1, -2}, 4))

}
