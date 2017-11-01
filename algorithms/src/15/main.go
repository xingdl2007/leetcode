package main

import "fmt"

// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
//
// Note: The solution set must not contain duplicate triplets.
//
// For example, given array S = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
// [-1, 0, 1],
// [-1, -1, 2]
// ]

//2695ms, shit!
type SkipList map[int]map[int]bool

func threeSum(nums []int) [][]int {
	skip := make(map[int]map[int]bool)
	record := make(map[int]bool)
	var ret [][]int

	for i, v := range nums {
		if _, ok := record[v]; !ok {
			record[v] = true
			ret = append(ret, twoSum(v, nums[i+1:], skip)...)
		}
	}
	return ret
}

func twoSum(src int, nums []int, skip SkipList) [][]int {
	tgt := -src
	record := make(map[int]bool)
	var ret [][]int

	for _, v := range nums {
		if _, ok := skip[src][v]; !ok {
			if _, ok := record[v]; ok {
				// find a match
				delete(record, v)

				pair := make([]int, 0, 3)
				pair = append(pair, src, tgt-v, v)
				ret = append(ret, pair)

				// maintain skipList
				if skip[src] == nil {
					skip[src] = make(map[int]bool)
				}
				if skip[v] == nil {
					skip[v] = make(map[int]bool)
				}
				if skip[tgt-v] == nil {
					skip[tgt-v] = make(map[int]bool)
				}
				skip[v][src] = true
				skip[tgt-v][src] = true

				skip[src][v] = true
				skip[src][tgt-v] = true
			} else {
				// add to record
				record[tgt-v] = true
			}
		}
	}

	return ret
}

func main() {
	S := []int{-1, 0, 1, 2, -1, -4}
	fmt.Println(threeSum(S))

	S = []int{-1, 0, 1, 2, -1, -4, 3, 1, 2, 3, 4, -12, -4, -5, -8, -1}
	fmt.Println(threeSum(S))
}
