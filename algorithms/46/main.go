package main

import (
	"fmt"
	"sort"
)

/**
	Given a collection of distinct numbers, return all possible permutations.

	For example,
	[1,2,3] have the following permutations:
	[
	  [1,2,3],
	  [1,3,2],
	  [2,1,3],
	  [2,3,1],
	  [3,1,2],
	  [3,2,1]
	]
 */

//Runtime: 12 ms, 56.67%
// recursive version
func permute(nums []int) [][]int {
	var ret [][]int
	size := len(nums)
	if size == 1 {
		ret = append(ret, nums)
	} else {
		p := permute(nums[:size-1])
		for i := 0; i < len(p); i++ {
			for j := 0; j < size; j++ {
				// must be new each iteration
				var tmp []int
				tmp = append(tmp, p[i][:j]...)
				tmp = append(tmp, nums[size-1])
				tmp = append(tmp, p[i][j:]...)
				ret = append(ret, tmp)
			}
		}
	}
	return ret
}

// backtracking
// Runtime: 9ms, 84.83%
func permute3(nums []int) [][]int {
	var perm func([]int, int)
	var res [][]int
	perm = func(l []int, n int) {
		// n == 0 make it can process nil slice
		if n == 0 {
			var tmp = make([]int, len(l))
			copy(tmp, l)
			res = append(res, tmp)
			return
		}
		for i := 0; i < n; i++ {
			l[n-1], l[i] = l[i], l[n-1]
			perm(l, n-1)
			l[n-1], l[i] = l[i], l[n-1]
		}
	}
	perm(nums, len(nums))
	return res
}

// a kind of LexicographicPermute: check
// Introduction to The Design and Analysis of Algorithms 3ed, p.112
func permute2(nums []int) [][]int {
	n := len(nums)
	var ans [][]int
	sort.Ints(nums)
	//fmt.Println(nums)
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
	fmt.Println(permute([]int{1, 2, 3}))
	fmt.Println(permute2([]int{1, 2, 3}))
	fmt.Println(permute3([]int{1, 2, 3}))
	fmt.Println(permute3([]int{}))
}
