package main

import (
	"fmt"
)

// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
// For example,
// X X X X
// X O O X
// X X O X
// X O X X
//
// After running your function, the board should be:
//
// X X X X
// X X X X
// X X X X
// X O X X

// 72 ms
func dfs(board [][]byte, i, j int) {
	if i < 0 || i >= len(board) || j < 0 || j >= len(board[0]) || board[i][j] != 'O' {
		return
	}
	board[i][j] = 'M'
	dfs(board, i, j-1)
	dfs(board, i, j+1)
	dfs(board, i-1, j)
	dfs(board, i+1, j)
}

func solve(board [][]byte) {
	row := len(board)
	if row == 0 {
		return
	}
	column := len(board[0])

	// start from boundary
	for j := 0; j < column; j++ {
		dfs(board, 0, j)
		dfs(board, row-1, j)
	}

	for i := 0; i < row; i++ {
		dfs(board, i, 0)
		dfs(board, i, column-1)
	}

	// set all internal 'O'->'X', 'M' -> 'O'
	for i, r := range board {
		for j, c := range r {
			if c == 'O' {
				board[i][j] = 'X'
			} else if c == 'M' {
				board[i][j] = 'O'
			}
		}
	}
}

// holy Shit: time limit exceeded in last test case
func solve2(board [][]byte) {
	row := len(board)
	if row == 0 {
		return
	}
	column := len(board[0])
	seen := make(map[int]bool)
	var flipping = func(element []int) {
		for _, coor := range element {
			i, j := coor/column, coor%column
			board[i][j] = 'X'
		}
	}
	for i, r := range board {
		for j, c := range r {
			if c == 'O' && !seen[i*column+j] {
				if found, region := dfs2(board, seen, i, j); found {
					flipping(region)
				}
			}
		}
	}
}

func dfs2(board [][]byte, seen map[int]bool, i, j int) (bool, []int) {
	row := len(board)
	column := len(board[0])
	var found = true
	var region []int

	if i < 0 || i >= row || j < 0 || j >= column || board[i][j] == 'X' || seen[i*column+j] {
		return true, nil
	}
	// boundary
	if i == 0 || i == row-1 || j == 0 || j == column-1 {
		found = false
		return found, nil
	}
	seen[i*column+j] = true
	region = append(region, i*column+j)
	f1, r1 := dfs2(board, seen, i-1, j)
	f2, r2 := dfs2(board, seen, i+1, j)
	f3, r3 := dfs2(board, seen, i, j-1)
	f4, r4 := dfs2(board, seen, i, j+1)
	found = found && f1 && f2 && f3 && f4
	region = append(region, r1...)
	region = append(region, r2...)
	region = append(region, r3...)
	region = append(region, r4...)

	return found, region
}

// fastest: clever!
func solve3(board [][]byte) {
	if len(board) == 0 {
		return
	}
	// top & bottom
	for j := 0; j < len(board[0]); j++ {
		mark(board, 0, j)
		mark(board, len(board)-1, j)
	}
	// left & right
	for i := 0; i < len(board); i++ {
		mark(board, i, 0)
		mark(board, i, len(board[0])-1)
	}

	for i := range board {
		for j := range board[i] {
			if board[i][j] == 'O' {
				board[i][j] = 'X'
			} else if board[i][j] == 'M' {
				board[i][j] = 'O'
			}
		}
	}
}

func mark(board [][]byte, x, y int) {
	if !inRange(board, x, y) || board[x][y] != 'O' {
		return
	}
	board[x][y] = 'M'
	mark(board, x, y+1)
	mark(board, x, y-1)
	mark(board, x+1, y)
	mark(board, x-1, y)
}

func inRange(board [][]byte, x, y int) bool {
	return x >= 0 && x < len(board) && y >= 0 && y < len(board[0])
}

type Grid [][]byte

func (g Grid) String() string {
	var str string
	for _, s := range g {
		str += string(s) + "\n"
	}
	return str
}
func main() {
	grid := [][]byte{
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'},
	}
	solve(grid)
	fmt.Println(Grid(grid))

	grid = [][]byte{
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'X', 'X'},
	}
	solve(grid)
	fmt.Println(Grid(grid))

	grid = [][]byte{
		{'O', 'X', 'X', 'O'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'},
		{'O', 'X', 'X', 'O'},
	}
	solve(grid)
	fmt.Println(Grid(grid))

	grid = [][]byte{
		{'O', 'O'},
		{'O', 'O'},
	}
	fmt.Println(Grid(grid))
}
