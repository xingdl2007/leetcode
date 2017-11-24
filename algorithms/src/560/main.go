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
// ref: https://leetcode.com/articles/subarray-sum-equals-k/
// method 4, impressive!

// Approach #4 Using hashmap [Accepted]
//
// Algorithm
//
// The idea behind this approach is as follows: If the cumulative sum(represented by sum[i] for sum up to i ​th index)
// up to two indices is the same, the sum of the elements lying in between those indices is zero. Extending the same
// thought further, if the cumulative sum up to two indices, say i and j is at a difference of k i.e.
// if sum[i] - sum[j] = k , the sum of elements lying between indices i and j is k.
//
// Based on these thoughts, we make use of a hash map which is used to store the cumulative sum upto all the
// indices possible along with the number of times the same sum occurs. We store the data in the form:
// (sum_i, no. of occurrences of sum_i).
//
// We traverse over the array num and keep on finding the cumulative sum.
// Every time we encounter a new sum, we make a new entry in the hash map corresponding to that sum.
// If the same sum occurs again, we increment the count corresponding to that sum in the hash map.
// Further, for every sum encountered, we also determine the number of times the sum sum-k has
// occurred already, since it will determine the number of times a sub array with sum kk has occurred up to the
// current index. We increment the count by the same amount.
//
//After the complete array has been traversed, the count gives the required result.
func subarraySum2(nums []int, k int) int {
	var count, sum int
	record := make(map[int]int)
	for _, n := range nums {
		record[sum]++
		sum += n
		count += record[sum-k]
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
