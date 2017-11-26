package main

import "fmt"

// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
// Example 1:
// [[1,3,1],
// [1,5,1],
// [4,2,1]]
//Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.

func minPathSum(grid [][]int) int {
	m := len(grid)
	if m == 0 {
		return 0
	}
	n := len(grid[0])
	if n == 0 {
		return 0
	}

	// first row
	for j := n - 2; j >= 0; j-- {
		grid[m-1][j] += grid[m-1][j+1]
	}

	// first column
	for i := m - 2; i >= 0; i-- {
		grid[i][n-1] += grid[i+1][n-1]
	}

	for i := m - 2; i >= 0; i-- {
		for j := n - 2; j >= 0; j-- {
			grid[i][j] += min(grid[i+1][j], grid[i][j+1])
		}
	}
	return grid[0][0]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	grid := [][]int{
		{1, 3, 1}, {1, 5, 1}, {4, 2, 1},
	}
	fmt.Println(minPathSum(grid))
}
