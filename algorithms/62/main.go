package main

import "fmt"

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot is trying to reach
// the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
// How many possible unique paths are there?
//
// Above is a 3 x 7 grid. How many possible unique paths are there?
//
// Note: m and n will be at most 100.
func uniquePaths(m int, n int) int {
	if m == 0 || n == 0 {
		return 0
	}
	paths := make([][]int, m)
	for i := 0; i < m; i++ {
		paths[i] = make([]int, n)
	}

	// first row
	for i := 0; i < n; i++ {
		paths[0][i] = 1
	}
	// first column
	for i := 0; i < m; i++ {
		paths[i][0] = 1
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			paths[i][j] = paths[i-1][j] + paths[i][j-1]
		}
	}
	return paths[m-1][n-1]
}

func main() {
	fmt.Println(uniquePaths(0, 0))
	fmt.Println(uniquePaths(1, 1))
	fmt.Println(uniquePaths(2, 2))
	fmt.Println(uniquePaths(2, 3))
	fmt.Println(uniquePaths(3, 7))
}
