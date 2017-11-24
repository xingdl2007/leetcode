package main

import "fmt"

// Your are given an array of positive integers nums.
//
// Count and print the number of (contiguous) subarrays where the product of all the elements
// in the subarray is less than k.
//
// Example 1:
// Input: nums = [10, 5, 2, 6], k = 100
//
// Output: 8
//
// Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
//
// Note:
//
// 0 < nums.length <= 50000.
// 0 < nums[i] < 1000.
// 0 <= k < 10^6.

// brute force, time limit exceeded
func numSubarrayProductLessThanK(nums []int, k int) int {
	var product, count int
	for i := 0; i < len(nums); i++ {
		product = 1
		for j := i; j < len(nums); j++ {
			product *= nums[j]
			if product < k {
				count++
			} else {
				break
			}
		}
	}
	return count
}

// try to do it better
// Runtime: 315 ms
func numSubarrayProductLessThanK2(nums []int, k int) int {
	var product = 1
	var count int
	for i, j := 0, 0; j < len(nums); j++ {
		product *= nums[j]
		for product >= k && i <= j {
			product /= nums[i]
			i++
		}
		// if i>j, j-i = -1, then count+=0, it's ok
		count += j - i + 1
	}
	return count
}

func main() {
	fmt.Println(numSubarrayProductLessThanK([]int{10, 5, 2, 6}, 80))
	fmt.Println(numSubarrayProductLessThanK2([]int{10, 5, 2, 6}, 80))
	fmt.Println(numSubarrayProductLessThanK2([]int{1, 2, 3}, 0))
}
