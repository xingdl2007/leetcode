package main

import (
	"math/rand"
	"time"
	"fmt"
)

// Shuffle a set of numbers without duplicates.

// Example:
//
// Init an array with set 1, 2, and 3.
// int[] nums = {1,2,3};
// Solution solution = new Solution(nums);
//
// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
// solution.shuffle();
//
// Resets the array back to its original configuration [1,2,3].
// solution.reset();
//
// Returns the random shuffling of array [1,2,3].
// solution.shuffle();
// ref: https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
type Solution struct {
	original []int
}

func Constructor(nums []int) Solution {
	rand.Seed(time.Now().UnixNano())
	return Solution{
		original: nums,
	}
}

/** Resets the array to its original configuration and return it. */
func (this *Solution) Reset() []int {
	return this.original
}

/** Returns a random shuffling of the array. */
func (this *Solution) Shuffle() []int {
	var res = make([]int, len(this.original))
	copy(res, this.original)
	for i := len(this.original) - 1; i > 0; i-- {
		j := rand.Intn(i + 1) // 0<= j <= i
		res[i], res[j] = res[j], res[i]
	}
	return res
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Reset();
 * param_2 := obj.Shuffle();
 */

func main() {
	obj := Constructor([]int{1, 2, 3, 4, 5, 6, 7, 8})
	fmt.Println(obj.Reset())
	fmt.Println(obj.Shuffle())
	fmt.Println(obj.Shuffle())
	fmt.Println(obj.Shuffle())
	fmt.Println(obj.Shuffle())
	fmt.Println(obj.Reset())
}
