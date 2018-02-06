package main

import "fmt"

// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//
// Follow up:
// Did you use extra space?
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
//
// Could you devise a constant space solution?

// impressive!
// ref: https://discuss.leetcode.com/topic/5056/any-shorter-o-1-space-solution
func setZeroes(matrix [][]int) {
	if len(matrix) == 0 {
		return
	}
	var iscol0has0 bool
	row, column := len(matrix), len(matrix[0])

	for i := 0; i < row; i++ {
		if matrix[i][0] == 0 {
			iscol0has0 = true
		}
		for j := 1; j < column; j++ {
			if matrix[i][j] == 0 {
				matrix[0][j], matrix[i][0] = 0, 0
			}
		}
	}

	for i := row - 1; i >= 0; i-- {
		for j := column - 1; j >= 1; j-- {
			if matrix[0][j] == 0 || matrix[i][0] == 0 {
				matrix[i][j] = 0
			}
		}
		if iscol0has0 {
			matrix[i][0] = 0
		}
	}
}

func print(matrix [][]int) {
	for _, line := range matrix {
		fmt.Println(line)
	}
	fmt.Println()
}

func main() {
	matrix := [][]int{
		{0, 2, 3}, {1, 2, 0},
	}
	print(matrix)
	setZeroes(matrix)
	print(matrix)

	setZeroes(nil)
}
