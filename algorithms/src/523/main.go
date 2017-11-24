package main

import (
	"fmt"
)

// Given a list of non-negative numbers and a target integer k, write a function to check
// if the array has a continuous subarray of size at least 2 that sums up to the multiple
// of k, that is, sums up to n*k where n is also an integer.
//
// Example 1:
// Input: [23, 2, 4, 6, 7],  k=6

// Output: True
// Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
//
// Example 2:
// Input: [23, 2, 6, 4, 7],  k=6
//
// Output: True
// Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
//
// Note:
// The length of the array won't exceed 10,000.
// You may assume the sum of all the numbers is in the range of a signed 32-bit integer.

// hash based
// shit: k may be negative?
func checkSubarraySum(nums []int, k int) bool {
	var sum int
	if k < 0 {
		k = -k
	}
	if k == 1 && len(nums) > 1 {
		return true
	}
	var record = map[int]int{}
	for i, n := range nums {
		if _, ok := record[sum]; !ok {
			record[sum] = i - 1
		}
		sum += n

		// adjacent 0
		if n == 0 {
			if i != 0 && nums[i-1] == 0 {
				return true
			}
			if i != len(nums)-1 && nums[i+1] == 0 {
				return true
			}
		}
		for sum >= k {
			if j, ok := record[sum-k]; ok {
				//fmt.Println(i, j)
				if i-j >= 2 {
					return true
				}
			}
			if k == 0 {
				break
			}
			sum -= k
		}
	}
	return false
}

// lots of corner case
// impressive, % not -, and can handle negative condition
func checkSubarraySum2(nums []int, k int) bool {
	n := len(nums)
	if n == 0 {
		return k == 0
	}
	m := make(map[int]int)
	m[0] = -1
	sum := 0
	for i, v := range nums {
		sum = sum + v
		r := sum
		if k != 0 {
			r = r % k
		}
		//find
		if index, ok := m[r]; ok && i-index >= 2 {
			return true
		}
		if _, ok := m[r]; !ok {
			m[r] = i
		}
	}
	return false
}

func main() {
	//fmt.Println(checkSubarraySum([]int{0, 0}, 0))
	//fmt.Println(checkSubarraySum([]int{23, 2, 4, 6, 7}, 7))
	//fmt.Println(checkSubarraySum([]int{23, 2, 6, 4, 7}, 6))
	//fmt.Println(checkSubarraySum([]int{23}, 23))
	//fmt.Println(checkSubarraySum([]int{2, 3, 1}, 2))
	//fmt.Println(checkSubarraySum([]int{2, 1, 3}, 3))
	//fmt.Println(checkSubarraySum([]int{2, 3}, 5))
	fmt.Println(checkSubarraySum2([]int{2, 3, 3, 4, 5, 0, 0, 1, 1, 3, 4, 5, 6}, -800))
	//
	//// -6
	//fmt.Println(checkSubarraySum([]int{23, 2, 4, 6, 7}, -6))
	//fmt.Println(checkSubarraySum2([]int{0}, 0))
	//fmt.Println(checkSubarraySum2([]int{0, 0}, -1))
	//fmt.Println(checkSubarraySum2([]int{1, 1000000000}, 1))
	fmt.Println(5 / -3, 5 % -3)
}
