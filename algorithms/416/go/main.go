package main

import (
	"fmt"
	"math/rand"
)

// Given a non-empty array containing only positive integers, find if the array can be
// partitioned into two subsets such that the sum of elements in both subsets is equal.

// Note:
// Each of the array element will not exceed 100.
// The array size will not exceed 200.
//
// Example 1:
//
// Input: [1, 5, 11, 5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
//
// Example 2:
//
// Input: [1, 2, 3, 5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

// very interesting !
// try it with backtracking, time limit exceed, not AC
func canPartition(nums []int) bool {
	var sum int
	for _, v := range nums {
		sum += v
	}
	// odd or even?
	half := sum >> 1
	if half<<1 != sum {
		return false
	}
	sum = 0
	var pos []int
	for i := 0; i < len(nums); i++ {
		sum += nums[i]
		if sum == half {
			return true
		} else if sum < half {
			pos = append(pos, i)
		} else {
			sum -= nums[i]
		}
		// backtracking part, may be too slow for some input
		// need worst case guarantee
		for i == len(nums)-1 && len(pos) > 0 {
			i = pos[len(pos)-1]
			sum -= nums[i]
			pos = pos[:len(pos)-1]
		}
	}
	return false
}

// actually knapsack problem, try to solve it with dynamic programming
// AC: Runtime: 59 ms, 45%
func canPartition2(nums []int) bool {
	var sum int
	for _, v := range nums {
		sum += v
	}
	// odd or even?
	half := sum >> 1
	if half<<1 != sum {
		return false
	}

	// dp table
	var dp = make([][]int, len(nums)+1)
	for i := 0; i < len(dp); i++ {
		dp[i] = make([]int, half+1)
	}

	// can be optimization with memory function
	// only compute value necessarily
	for i := 1; i < len(dp); i++ {
		for j := 1; j <= half; j++ {
			if nums[i-1] > j {
				dp[i][j] = dp[i-1][j]
			} else {
				dp[i][j] = max(dp[i-1][j], nums[i-1]+dp[i-1][j-nums[i-1]])
			}
		}
	}
	return dp[len(dp)-1][half] == half
}

// Optimization space usage
// AC: Runtime: 22 ms, 72%
func canPartition3(nums []int) bool {
	var sum int
	for _, v := range nums {
		sum += v
	}
	// odd or even?
	half := sum >> 1
	if half<<1 != sum {
		return false
	}
	// dp table (can use bool slice, just like canPartition4
	// which is better!)
	var dp = make([]int, half+1)
	for _, v := range nums {
		// Note: must be descending order, to use last line
		for j := half; j >= v; j-- {
			dp[j] = max(dp[j], v+dp[j-v])
		}
	}
	// what we get in knapsack
	return dp[half] == half
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// ref from leetcode
func canPartition4(nums []int) bool {
	if len(nums) <= 1 {
		return false
	}
	sum := 0
	for i := 0; i < len(nums); i++ {
		sum += nums[i]
	}

	if sum%2 != 0 {
		return false
	}
	half := sum / 2
	// why do this check?
	half -= nums[0]
	if half < 0 {
		return false
	} else if half == 0 {
		return true
	}
	nums = nums[1:]
	dp := make([]bool, half+1)
	dp[0] = true
	for i := 0; i < len(nums); i++ {
		for j := half; j >= nums[i]; j-- {
			dp[j] = dp[j] || dp[j-nums[i]]
		}
		if dp[half] == true {
			return true
		}
	}
	return dp[half]
}

func shuffle(nums [] int) {
	for i := len(nums) - 1; i > 0; i-- {
		j := rand.Intn(i + 1)
		nums[i], nums[j] = nums[j], nums[i]
	}
}

func main() {
	fmt.Println(canPartition([]int{1, 5, 11, 5}))
	fmt.Println(canPartition([]int{1, 2, 3, 5}))

	fmt.Println()
	nums := []int{1, 2, 3, 4, 5, 6, 7}
	for i := 0; i < 100; i++ {
		shuffle(nums)
		if !canPartition2(nums) {
			fmt.Println(nums)
		}
	}

	fmt.Println(canPartition2([]int{1, 5, 11, 5}))
	fmt.Println(canPartition2([]int{1, 2, 3, 5}))

	fmt.Println()
	// backtracking method is too slow for this type of input
	// dp is better
	nums = []int{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 20}
	fmt.Println(canPartition(nums))
	fmt.Println(canPartition2(nums))
	fmt.Println(canPartition3(nums))
	fmt.Println(canPartition4(nums))
}
