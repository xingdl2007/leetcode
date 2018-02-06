package main

import (
	"fmt"
)

// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
// prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
// find the duplicate one.
//
// Note:
// You must not modify the array (assume the array is read only).
// You must use only constant, O(1) extra space.
// Your runtime complexity should be less than O(n2).
// There is only one duplicate number in the array, but it could be repeated more than once.

// O(n*log(n))
func findDuplicate(nums []int) int {
	low, high := 1, len(nums)-1
	var mid int
loop:
	for {
		bigger, smaller, equal := 0, 0, 0
		mid = (low + high) / 2
		for i := 0; i < len(nums); i++ {
			if mid < nums[i] && nums[i] <= high {
				bigger++
			} else if low <= nums[i] && nums[i] < mid {
				smaller++
			} else if nums[i] == mid {
				if equal++; equal >= 2 {
					break loop
				}
			}
		}
		if smaller < bigger {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	return mid
}

// more succinct one
func findDuplicate2(nums []int) int {
	n := len(nums) - 1
	left := 1
	right := n
	for left < right {
		mid := left + (right-left)/2
		count := 0
		for i := 0; i < len(nums); i++ {
			if nums[i] <= mid {
				count++
			}
		}
		if count > mid {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}

// more fast: https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
func findDuplicate3(nums []int) int {
	slow, fast := 0, 0
	slow = nums[slow]
	fast = nums[nums[fast]]
	for slow != fast {
		slow = nums[slow]
		fast = nums[nums[fast]]
	}
	slow = 0
	for slow != fast {
		slow = nums[slow]
		fast = nums[fast]
	}
	return slow
}

// if can modify original array, pretty fast!!
// impressive!!!
func findDuplicate4(nums []int) int {
	for i := 0; i < len(nums); i++ {
		n := nums[i]
		if n < 0 {
			n *= -1
		}
		val := nums[n-1]
		if val < 0 {
			return n
		}
		nums[n-1] *= -1
		fmt.Println(nums)
	}
	return -1
}

func main() {
	array := []int{1, 2, 1, 4, 1, 6, 7, 1}
	fmt.Println(findDuplicate(array))

	array = []int{1, 2, 3, 4, 5, 6, 7, 2}
	fmt.Println(findDuplicate(array))

	array = []int{1, 2, 3, 4, 5, 3, 7, 3}
	fmt.Println(findDuplicate(array))

	array = []int{1, 4, 3, 4, 5, 4, 7, 4}
	fmt.Println(findDuplicate(array))

	array = []int{1, 5, 3, 5, 5, 6, 5, 5}
	fmt.Println(findDuplicate2(array))

	array = []int{6, 2, 3, 4, 5, 6, 7, 6}
	fmt.Println(findDuplicate3(array))

	array = []int{1, 2, 3, 4, 7, 5, 6, 7}
	fmt.Println(findDuplicate4(array))

}
