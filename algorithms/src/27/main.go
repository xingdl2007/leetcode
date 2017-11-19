package main

import "fmt"

// Given an array and a value, remove all instances of that value in-place and return the new length.
//
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//
// The order of elements can be changed. It doesn't matter what you leave beyond the new length.
//
// Example:
//
// Given nums = [3,2,2,3], val = 3,
//
// Your function should return length = 2, with the first two elements of nums being 2.

func removeElement(nums []int, val int) int {
	i, j := 0, len(nums)-1
	for {
		for i < len(nums) && nums[i] != val {
			i++
		}
		for j >= 0 && nums[j] == val {
			j--
		}
		if i >= len(nums) || j < 0 || i >= j {
			break
		}
		nums[i], nums[j] = nums[j], nums[i]
	}
	return i
}

func main() {
	arr := []int{3, 2, 2, 1, 2, 3, 4, 6, 7, 7, 3}
	fmt.Println(removeElement(arr, 3))
	fmt.Println(arr)

	arr = []int{3}
	fmt.Println(removeElement(arr, 3))
	fmt.Println(arr)

	arr = []int{}
	fmt.Println(removeElement(arr, 3))
	fmt.Println(arr)
}
