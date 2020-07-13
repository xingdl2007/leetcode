package main

import (
	"fmt"
)

// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.
//
// Example 1:
//
// 11110
// 11010
// 11000
// 00000
//
// Answer: 1
//
// Example 2:
//
// 11000
// 11000
// 00100
// 00011
//
// Answer: 3

// byte!
func numIslands(grid [][]byte) int {
	if len(grid) == 0 {
		return 0
	}
	row := len(grid)
	column := len(grid[0])
	var island = row * column
	var id = make([]int, island)
	for i := range id {
		id[i] = i
	}
	var union = func(s, d int) {
		for i, v := range id {
			if v == id[s] {
				id[i] = id[d]
			}
		}
		island--
	}
	for i, r := range grid {
		for j, c := range r {
			if c == '1' {
				// skip left corner
				if i == 0 && j == 0 {
					continue
				}
				// left
				if j != 0 && grid[i][j-1] == '1' && id[i*column+j] != id[i*column+j-1] {
					union(i*column+j, i*column+j-1)
				}
				// upper
				if i != 0 && grid[i-1][j] == '1' && id[(i-1)*column+j] != id[i*column+j] {
					union(i*column+j, (i-1)*column+j)
				}
			} else {
				island--
			}
		}
	}
	return island
}

// DFS
// if can modify gird, will same O(n) extra set space
func numIslands2(grid [][]byte) int {
	if len(grid) == 0 {
		return 0
	}
	row := len(grid)
	column := len(grid[0])
	var id int
	var dfs func(i, j int)
	dfs = func(i, j int) {
		if i < 0 || i >= row || j < 0 || j >= column || grid[i][j] == '0' {
			return
		}
		if grid[i][j] == '1' {
			grid[i][j] = '0'
		}
		// lazy check
		dfs(i-1, j)
		dfs(i+1, j)
		dfs(i, j-1)
		dfs(i, j+1)
	}
	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] == '1' {
				dfs(i, j)
				id++
			}
		}
	}
	return id
}

func main() {
	grid := [][]byte{
		{'1', '1', '1', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},
	}
	fmt.Println(numIslands(grid))
	fmt.Println(numIslands2(grid))

	grid = [][]byte{
		{'1', '1', '0', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '1', '1'},
	}
	fmt.Println(numIslands(grid))
	fmt.Println(numIslands2(grid))
	fmt.Println(numIslands([][]byte{}))
	fmt.Println(numIslands2([][]byte{}))
	fmt.Println(numIslands([][]byte{{'1', '0'}, {'0', '1'}}))
	fmt.Println(numIslands2([][]byte{{'1', '0'}, {'0', '1'}}))
	fmt.Println(numIslands([][]byte{{'1', '1', '1', '1', '1', '0'}}))
	fmt.Println(numIslands2([][]byte{{'1', '1', '1', '1', '1', '0'}}))

	grid = [][]byte{
		{'0'},
		{'1'},
		{'0'},
		{'1'},
		{'1'},
	}
	fmt.Println(numIslands(grid))
	fmt.Println(numIslands2(grid))

	grid = [][]byte{
		{'1', '1', '1', '1', '0'},
		{'1', '1', '0', '1', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '0', '0', '0', '0'},}
	fmt.Println(numIslands(grid))
	fmt.Println(numIslands2(grid))
}
