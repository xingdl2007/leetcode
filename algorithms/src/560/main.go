package main

import "fmt"

// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
//
// Example 1:
//
// Input:nums = [1,1,1], k = 2
// Output: 2
//
// Note:
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

// shit! forget negetive number!!
// fk, == is also not
func subarraySum(nums []int, k int) int {
	var count int
	sum := 0
	for i := 0; i < len(nums); i++ {
		for j := i; j < len(nums); j++ {
			sum += nums[j]
			if sum == k {
				count++
			}
		}
		sum = 0
	}
	return count
}

// map based
func subarraySum2(nums []int, k int) int {
	var count, sum int
	record := make(map[int]int)
	record[0] = 1
	for _, n := range nums {
		sum += n
		if v, ok := record[sum-k]; ok {
			count += v
		}
		record[sum]++
	}
	return count
}

func main() {
	//fmt.Println(subarraySum([]int{1, 1, 1, 6, 1, 1, 1, 1, 1}, 2))
	fmt.Println(subarraySum2([]int{1, 8, 1, 2, 3, 6, 2, 9, 1, 1}, 9))
	fmt.Println(subarraySum2([]int{1}, 0))
	fmt.Println(subarraySum2([]int{}, 0))

	// good test
	fmt.Println(subarraySum2([]int{28, 54, 7, -70, 22, 65, -6}, 100))

	fmt.Println(subarraySum2([]int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0))
}
