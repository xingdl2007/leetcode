package main

import (
	"fmt"
)

// The set S originally contains numbers from 1 to n. But unfortunately,
// due to the data error, one of the numbers in the set got duplicated to
// another number in the set, which results in repetition of one number
// and loss of another number.
//
// Given an array nums representing the data status of this set after the error.
// Your task is to firstly find the number occurs twice and then find the number
// that is missing. Return them in the form of an array.
//
// Example 1:
// Input: nums = [1,2,2,4]
// Output: [2,3]
//
// Note:
// The given array size will in the range [2, 10000].
// The given array's numbers won't have any order.

func findErrorNums(nums []int) []int {
	var ret = make([]int, 2)
	// hash
	record := make(map[int]struct{})
	for _, n := range nums {
		if _, ok := record[n]; ok {
			ret[0] = n
			break
		} else {
			record[n] = struct{}{}
		}
	}
	// then use math to find the missing one
	ret[1] = len(nums) * (len(nums) + 1) / 2

	for _, n := range nums {
		ret[1] -= n
	}
	ret[1] += ret[0]
	return ret
}

/**
public class Solution {
    public int[] findErrorNums(int[] nums) {
        int dup = -1, missing = 1;
        for (int n: nums) {
            if (nums[Math.abs(n) - 1] < 0)
                dup = Math.abs(n);
            else
                nums[Math.abs(n) - 1] *= -1;
        }
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > 0)
                missing = i + 1;
        }
        return new int[]{dup, missing};
    }
}
*/

// https://leetcode.com/articles/set-mismatch/
// impressive, especially the method of find missing number!
func findErrorNums2(nums []int) []int {
	dup, missing := -1, 1
	for i := 0; i < len(nums); i++ {
		n := nums[i]
		if n < 0 {
			n = -n
		}
		if nums[n-1] < 0 {
			dup = n
		} else {
			nums[n-1] = -nums[n-1]
		}
	}
	for i, v := range nums {
		if v > 0 {
			missing = i + 1
		}
	}
	return []int{dup, missing}
}

func main() {
	nums := []int{1, 2, 3, 3, 4, 5, 6}
	fmt.Println(findErrorNums(nums))

	fmt.Println(findErrorNums2(nums))
}
