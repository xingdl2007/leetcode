package main

import "fmt"

// Follow up for "Unique Paths":
//
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
//
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
// [
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
// ]
// The total number of unique paths is 2.

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	m := len(obstacleGrid)
	if m == 0 {
		return 0
	}
	n := len(obstacleGrid[0])
	if n == 0 {
		return 0
	}

	paths := make([][]int, m)
	for i := 0; i < m; i++ {
		paths[i] = make([]int, n)
	}
	// first row
	var isBlocked bool
	for i := 0; i < n; i++ {
		if obstacleGrid[0][i] == 1 {
			isBlocked = true
		}
		if isBlocked {
			paths[0][i] = 0
		} else {
			paths[0][i] = 1
		}
	}
	// first column
	isBlocked = false
	for i := 0; i < m; i++ {
		if obstacleGrid[i][0] == 1 {
			isBlocked = true
		}
		if isBlocked {
			paths[i][0] = 0
		} else {
			paths[i][0] = 1
		}
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if obstacleGrid[i][j] == 1 {
				paths[i][j] = 0
			} else {
				paths[i][j] = paths[i-1][j] + paths[i][j-1]
			}
		}
	}
	return paths[m-1][n-1]
}

func main() {
	obstacleGrid := [][]int{
		{0, 0, 0}, {0, 1, 0}, {0, 0, 0},
	}
	fmt.Println(uniquePathsWithObstacles(obstacleGrid))
}
