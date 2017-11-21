package main

import "fmt"

// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//
// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,-1,2,1] has the largest sum = 6.

// Runtime: 12 ms, 60%
func maxSubArray(nums []int) int {
	var max = nums[0]
	var sum int
	for _, n := range nums {
		sum += n
		if max < sum {
			max = sum
		}
		if sum < 0 {
			sum = 0
		}
	}
	return max
}

func main() {
	fmt.Println(maxSubArray([]int{-2, 1, -3, 4, -1, 2, 1, -5, 4}))
	fmt.Println(maxSubArray([]int{-2}))
	fmt.Println(maxSubArray([]int{-2, -1}))
}
