package main

import "fmt"

// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land)
// connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//
// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
//
// Example 1:
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,1,1,0,1,0,0,0,0,0,0,0,0],
// [0,1,0,0,1,1,0,0,1,0,1,0,0],
// [0,1,0,0,1,1,0,0,1,1,1,0,0],
// [0,0,0,0,0,0,0,0,0,0,1,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,0,0,0,0,0,0,1,1,0,0,0,0]]
//
// Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
//
// Example 2:
// [[0,0,0,0,0,0,0,0]]
//
// Given the above grid, return 0.
// Note: The length of each dimension in the given grid does not exceed 50.

func maxAreaOfIsland(grid [][]int) int {
	if len(grid) == 0 {
		return 0
	}
	row := len(grid)
	column := len(grid[0])
	var area int
	var dfs func(i, j int) int
	dfs = func(i, j int) (count int) {
		if i < 0 || i >= row || j < 0 || j >= column || grid[i][j] == 0 {
			return
		}
		if grid[i][j] == 1 {
			grid[i][j] = 0
			count++
		}
		// lazy check
		count += dfs(i-1, j)
		count += dfs(i+1, j)
		count += dfs(i, j-1)
		count += dfs(i, j+1)
		return
	}
	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] == 1 {
				tmp := dfs(i, j)
				if area < tmp {
					area = tmp
				}
			}
		}
	}
	return area
}

func main() {
	grid := [][]int{
		{1, 1, 1, 1, 0},
		{1, 1, 0, 1, 0},
		{1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0},
	}
	fmt.Println(maxAreaOfIsland(grid))

	grid = [][]int{
		{1, 1, 0, 0, 0},
		{1, 1, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 1, 1},
	}
	fmt.Println(maxAreaOfIsland(grid))

	fmt.Println(maxAreaOfIsland([][]int{{0, 0, 0, 0}}))

	fmt.Println(maxAreaOfIsland([][]int{{1, 0}, {0, 1}}))
	fmt.Println(maxAreaOfIsland([][]int{{1, 1, 1, 1, 1, 0}}))

	grid = [][]int{
		{0},
		{1},
		{0},
		{1},
		{1},
	}
	fmt.Println(maxAreaOfIsland(grid))

	grid = [][]int{
		{1, 1, 1, 1, 0},
		{1, 1, 0, 1, 0},
		{1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0},}
	fmt.Println(maxAreaOfIsland(grid))

	grid = [][]int{
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
	}
	fmt.Println(maxAreaOfIsland(grid))
}
