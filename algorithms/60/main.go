package main

import (
	"sort"
	"strconv"
	"fmt"
)

// The set [1,2,3,…,n] contains a total of n! unique permutations.
//
// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):
//
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
//
// Given n and k, return the kth permutation sequence.
//
// Note: Given n will be between 1 and 9 inclusive.
//

// Another lexicographic order, can generate according to k?
// interesting
// Runtime: 219ms, 29%
// TODO: try to do it better
func fact(n int) (ret int) {
	ret = 1
	for i := 2; i <= n; i++ {
		ret *= i
	}
	return
}
func getPermutation(n int, k int) string {
	var nums = make([]int, n)
	var cnt int
	var ret string
	for i := 0; i < n; i++ {
		nums[i] = i + 1
	}
	// find first element
	tmp := fact(n - 1)
	if tmp != 1 {
		i := (k + 1) / tmp
		if i != 0 {
			nums[0], nums[i-1] = nums[i-1], nums[0]
			sort.Ints(nums[1:])
			cnt = tmp * (i - 1)
		}
	}
	for {
		cnt++
		if cnt == k {
			for _, v := range nums {
				ret += strconv.Itoa(v)
			}
			return ret
		}
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
		// swap with the smallest one which is bigger than nums[pos]
		for i := pos; i < n; i++ {
			if nums[i] > nums[pos-1] {
				nums[i], nums[pos-1] = nums[pos-1], nums[i]
				break
			}
		}
	}
	return ret
}

// impressive, bottom up, elegant
func getPermutation2(n int, k int) string {
	nums, result := make([]byte, n), make([]byte, n)
	for i := 0; i < n; i++ {
		nums[i] = byte(i) + 1
	}
	k--
	for i := 1; i <= n; i++ {
		index := k / fact(n-i)
		result[i-1] = '0' + nums[index]
		nums = append(nums[:index], nums[index+1:]...)
		k -= index * fact(n-i)
	}
	return string(result)
}

func main() {
	fmt.Println(getPermutation(3, 1))
	fmt.Println(getPermutation(3, 2))
	fmt.Println(getPermutation(3, 3))
	fmt.Println(getPermutation(3, 4))
	fmt.Println(getPermutation(3, 5))
	fmt.Println(getPermutation(3, 6))
	// output:
	// 123
	// 132
	// 213
	// 231
	// 312
	// 321
	fmt.Println(getPermutation(1, 1))
	fmt.Println(getPermutation(2, 1))
	fmt.Println(getPermutation(2, 2))
	fmt.Println(getPermutation(4, 1))
}
