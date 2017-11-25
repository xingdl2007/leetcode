package main

import "fmt"

// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to
// adjacent numbers on the row below.
//
// For example, given the following triangle
// [
//      [2],
//     [3,4],
//    [6,5,7],
//  [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total
// number of rows in the triangle.

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minimumTotal(triangle [][]int) int {
	row := len(triangle)
	if row == 0 {
		return 0
	}
	aux := make([]int, row)
	copy(aux, triangle[row-1])
	for i := row - 2; i >= 0; i-- {
		for j := 0; j < len(triangle[i]); j++ {
			aux[j] = min(aux[j], aux[j+1]) + triangle[i][j]
		}
	}
	return aux[0]
}

func main() {
	triangle := [][]int{
		{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3},
	}
	fmt.Println(minimumTotal(triangle))
	fmt.Println(minimumTotal(nil))
}
