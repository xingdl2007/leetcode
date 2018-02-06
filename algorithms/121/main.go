package main

import (
	"math"
	"fmt"
)

// Say you have an array for which the ith element is the price of a given stock on day i.
//
// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
// Example 1:
// Input: [7, 1, 5, 3, 6, 4]
// Output: 5
//
// max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
// Example 2:
// Input: [7, 6, 4, 3, 1]
// Output: 0
//
// In this case, no transaction is done, i.e. max profit = 0.

// Runtime: 9 ms, 55%
// Space: O(n)
// Time: O(n)
func maxProfit(prices []int) int {
	if len(prices) == 0 {
		return 0
	}
	min := make([]int, len(prices))
	max := make([]int, len(prices))

	compare := math.MaxUint32
	for i := 0; i < len(prices); i++ {
		if prices[i] < compare {
			min[i] = prices[i]
			compare = min[i]
		} else {
			min[i] = compare
		}
	}

	compare = -1
	for i := len(prices) - 1; i >= 0; i-- {
		if prices[i] > compare {
			max[i] = prices[i]
			compare = max[i]
		} else {
			max[i] = compare
		}
	}

	profit := 0
	for i := 0; i < len(prices); i++ {
		p := max[i] - min[i]
		if p > profit {
			profit = p
		}
	}
	return profit
}

// better method
// Space: O(1)
// Time: O(n)
func maxProfit2(prices []int) int {
	maxProfit := 0
	if len(prices) == 0 {
		return 0
	}
	buyCost := prices[0]
	for _, cost := range prices {
		diff := cost - buyCost
		if diff > maxProfit {
			maxProfit = diff
		}
		if cost < buyCost {
			buyCost = cost
		}
	}
	return maxProfit
}

func main() {
	fmt.Println(maxProfit([]int{7, 1, 5, 3, 6, 4}))
	fmt.Println(maxProfit([]int{7, 6, 4, 3, 1}))
}
