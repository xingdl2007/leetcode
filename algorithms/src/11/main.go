/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

package main

import (
	"fmt"
)

// although accepted, not the best solution
// Space complexity: O(1)
// Time complexigty: O(n2)-- worst case
func maxArea(height []int) int {
	var area, tmp int

	for i, v := range height {
		j, k := 0, len(height)-1

		for ; j < i; j++ {
			if height[j] >= v {
				break
			}
		}

		for ; k > i; k-- {
			if height[k] >= v {
				break
			}
		}

		// max value
		if j == i && i == k {
			continue
		}

		if i-j > k-i {
			tmp = (i - j) * v
		} else {
			tmp = (k - i) * v
		}

		if area < tmp {
			area = tmp
		}
	}

	return area
}

// Space Complexity: O(1)
// Time Complexity: O(n)
// faster: about 26ms
func maxArea2(height []int) int {
	var area, tmp int
	l, r := 0, len(height)-1
	len := r - l

	for l < r {
		if height[l] < height[r] {
			tmp = len * height[l]
			l++
		} else {
			tmp = len * height[r]
			r--
		}
		if area < tmp {
			area = tmp
		}
		len--
	}
	return area
}

// faster: about 29ms
//func maxArea(height []int) int {
//	var area, tmp int
//	l, r := 0, len(height)-1
//
//	for l < r {
//		tmp = r - l
//
//		if height[l] < height[r] {
//			tmp *= height[l]
//			l++
//		} else {
//			tmp *= height[r]
//			r--
//		}
//		if area < tmp {
//			area = tmp
//		}
//	}
//
//	return area
//}

func main() {
	fmt.Println(maxArea([]int{1, 1, 1, 1, 1}))
	fmt.Println(maxArea([]int{2, 3, 1, 4, 6, 2, 1, 5}))

	fmt.Println(maxArea2([]int{1, 1, 1, 1, 1}))
	fmt.Println(maxArea2([]int{2, 3, 1, 4, 6, 2, 1, 5}))
}
