package main

import (
	"fmt"
	"sort"
)

// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//
// Your algorithm should run in O(n) complexity.

// sort based, O(nlogn)
func longestConsecutive(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	sort.Ints(nums)

	// Note: take care of the boundary
	// only have one element
	var count, tmp = 1, 1
	for i := 1; i < len(nums); i++ {
		if nums[i] == nums[i-1]+1 {
			tmp++
		} else if nums[i] > nums[i-1] {
			if count < tmp {
				count = tmp
			}
			tmp = 1
		}
	}
	// last one
	if count < tmp {
		count = tmp
	}
	return count
}

// map based
func longestConsecutive2(nums []int) int {
	var record = make(map[int]struct{})
	for _, n := range nums {
		record[n] = struct{}{}
	}
	var length, aux int
	// start from smallest
	for _, n := range nums {
		if _, ok := record[n-1]; !ok {
			aux++
			tmp := n
			for _, ok := record[tmp+1]; ok; _, ok = record[tmp+1] {
				aux++
				tmp++
			}
			if length < aux {
				length = aux
			}
			aux = 0
		}
	}
	if length < aux {
		return aux
	}
	return length
}

// clever ! only need to set boundary
func longestConsecutive3(nums []int) int {
	m := make(map[int]int)
	max := 0
	for _, n := range nums {
		if m[n] == 0 {
			left := m[n-1]
			right := m[n+1]
			s := left + right + 1

			m[n] = s // mark it as being visited.
			m[n-left] = s
			m[n+right] = s
			if max < s {
				max = s
			}
		}
	}
	return max
}

func main() {
	array := []int{100, 4, 200, 0, -1, 3, 2, 99, 101, 102, 1}
	fmt.Println(longestConsecutive(array))
	fmt.Println(longestConsecutive([]int{0}))
	fmt.Println(longestConsecutive([]int{0, -1}))

	fmt.Println(longestConsecutive2([]int{100, 4, 200, 0, -1, 3, 2, 99, 101, 102, 1}))
	fmt.Println(longestConsecutive2([]int{0}))
	fmt.Println(longestConsecutive2([]int{0, -1}))
}
