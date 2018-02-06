package main

import (
	"fmt"
)

// Given an unsorted integer array, find the first missing positive integer.
//
// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.
//
// Your algorithm should run in O(n) time and uses constant space.

// shit! Nums may have duplicate positive integer
// Note: not right!
func firstMissingPositiveWrong(nums []int) int {
	var sum int
	var count int
	for _, n := range nums {
		if n > 0 {
			sum += n
			if n > count {
				count = n
			}
		}
	}
	ret := count*(count+1)/2 - sum
	if ret == 0 {
		return count + 1
	}
	return ret
}

/*
ref: https://discuss.leetcode.com/topic/10351/o-1-space-java-solution

The key here is to use swapping to keep constant space and also make use of the length of the array,
which means there can be at most n positive integers. So each time we encounter an valid integer,
find its correct position and swap. Otherwise we continue.

public class Solution {
    public int firstMissingPositive(int[] A) {
        int i = 0;
        while(i < A.length){
            if(A[i] == i+1 || A[i] <= 0 || A[i] > A.length) i++;
            else if(A[A[i]-1] != A[i]) swap(A, i, A[i]-1);
            else i++;
        }
        i = 0;
        while(i < A.length && A[i] == i+1) i++;
        return i+1;
    }

    private void swap(int[] A, int i, int j){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}
 */
func firstMissingPositive(nums []int) int {
	i := 0
	for i < len(nums) {
		if nums[i] == i+1 || nums[i] <= 0 || nums[i] > len(nums) {
			i++
		} else if nums[i] != nums[nums[i]-1] {
			j := nums[i] - 1
			nums[i], nums[j] = nums[j], nums[i]
		} else {
			// duplicate element
			i++
		}
	}

	i = 0
	for i < len(nums) && nums[i] == i+1 {
		i++
	}
	return i + 1
}

func main() {
	// show result
	fmt.Println(firstMissingPositive([]int{1, 2, 0}))
	fmt.Println(firstMissingPositive([]int{3, 4, -1, 1}))
	fmt.Println(firstMissingPositive([]int{1, 1}))
	fmt.Println(firstMissingPositive([]int{2, 2}))
	fmt.Println(firstMissingPositive([]int{}))
	fmt.Println(firstMissingPositive([]int{1}))
}
