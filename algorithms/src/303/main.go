package main

import "fmt"

// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//
// Example:
// Given nums = [-2, 0, 3, -5, 2, -1]
//
// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3
// Note:
// You may assume that the array does not change.
// There are many calls to sumRange function.

type NumArray struct {
	sum map[int]int
}

func Constructor(nums []int) NumArray {
	sum := make(map[int]int)
	var s int
	for i, n := range nums {
		s += n
		sum[i] = s
	}
	return NumArray{sum: sum}
}

func (this *NumArray) SumRange(i int, j int) int {
	return this.sum[j] - this.sum[i-1]
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */

func main() {
	num := Constructor([]int{-2, 0, 3, -5, 2, -1})
	fmt.Println(num.SumRange(0, 2))
	fmt.Println(num.SumRange(2, 5))
	fmt.Println(num.SumRange(0, 5))
}
