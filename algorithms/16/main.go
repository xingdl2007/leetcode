package main

import (
	"sort"
	"fmt"
)

// Given an array S of n integers, find three integers in S such that the sum is closest
// to a given number, target. Return the sum of the three integers. You may assume that
// each input would have exactly one solution.
//
// For example, given array S = {-1 2 1 -4}, and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// Runtime: 9 ms
func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	var closest, sum int

	// must be true
	if len(nums) > 2 {
		closest = nums[0] + nums[1] + nums[2]
	}

	for i := 0; i < len(nums)-2; i++ {
		if i == 0 || (i > 0 && nums[i] != nums[i-1]) {
			lo, hi := i+1, len(nums)-1
			for lo < hi {
				sum = nums[lo] + nums[hi] + nums[i]
				if sum < target {
					if closest < target && target-sum < target-closest {
						closest = sum
					} else if target < closest && target-sum < closest-target {
						closest = sum
					}
					for lo < hi && nums[lo] == nums[lo+1] {
						lo++
					}
					lo++
				} else if sum > target {
					if closest < target && sum-target < target-closest {
						closest = sum
					} else if target < closest && sum-target < closest-target {
						closest = sum
					}
					for lo < hi && nums[hi] == nums[hi-1] {
						hi--
					}
					hi--
				} else {
					return target
				}
			}
		}
	}

	return closest
}

func main() {
	fmt.Println(threeSumClosest([]int{-1, 2, 1, -4}, 1))

	fmt.Println(threeSumClosest([]int{-1, 2, 8, 3, 2, 3, 6, 1, -4}, 20))

	fmt.Println(threeSumClosest([]int{0, 1, 2}, 0))

}
