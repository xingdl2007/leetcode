package main

import "fmt"

// Find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
// For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6.

// 0 is split point
// Runtime: 6ms, about 46.67%
func maxProduct(nums []int) int {
	if len(nums) == 1 {
		return nums[0]
	}
	var product = 0
	var i int
	var cnt, left, right = 0, -1, -1
	for j, k := range nums {
		if k < 0 {
			cnt++
			if left == -1 {
				left = j - i
			}
			if j > right {
				right = j - i
			}
		}
		// split point
		if k == 0 {
			if i != j {
				if p := maxProductWithoutZero(nums[i:j], cnt, left, right); product < p {
					product = p
				}
			}
			i = j + 1
			cnt, left, right = 0, -1, -1
		}
	}
	// last one
	if i != len(nums) {
		if p := maxProductWithoutZero(nums[i:], cnt, left, right); product < p {
			product = p
		}
	}
	return product
}

func maxProductWithoutZero(nums []int, cnt, left, right int) int {
	if len(nums) == 1 {
		return nums[0]
	}
	var product = 1
	if cnt%2 == 0 {
		for _, n := range nums {
			product *= n
		}
	} else {
		// left
		var p1, p2 = 1, 1
		for i := left + 1; i < len(nums); i++ {
			p1 *= nums[i]
		}
		// right
		for i := 0; i < right; i++ {
			p2 *= nums[i]
		}
		product = max(p1, p2)
	}
	return product
}

// maybe too clever!
func maxProduct2(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	res, maxP, minP := nums[0], nums[0], nums[0]
	for i := 1; i < len(nums); i++ {
		n := nums[i]
		maxP, minP = max(n, max(n*minP, n*maxP)), min(n, min(n*minP, n*maxP))
		res = max(res, maxP)
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Println(maxProduct([]int{2, 0, -3, 0, -2, 4}))
	fmt.Println(maxProduct([]int{-2}))
	fmt.Println(maxProduct([]int{-2, -2}))
	fmt.Println(maxProduct([]int{-2, 0, -1}))
	fmt.Println(maxProduct([]int{-2, 0, -1}))
	fmt.Println(maxProduct([]int{2, -3, 0, -2, 4, 10, 0, -30, -4, 2, 1, 0, 3, 25}))
	fmt.Println(maxProduct([]int{0, -2, 0}))
}
