package main

import "fmt"

// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
// For example,
// Given the following matrix:
//
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
//
// You should return [1,2,3,6,9,8,7,4,5].

func spiralOrder(matrix [][]int) []int {
	row := len(matrix)
	if row == 0 {
		return nil
	}
	col := len(matrix[0])
	var res = make([]int, 0, row*col)

	for len(matrix) != 0 {
		// first row
		res = append(res, matrix[0]...)
		matrix = matrix[1:]

		// last column
		for i, r := range matrix {
			if len(r) > 0 {
				res = append(res, r[len(r)-1])
				matrix[i] = matrix[i][:len(r)-1]
			}
		}

		// last row
		if len(matrix) != 0 {
			r := matrix[len(matrix)-1]
			for i := len(r) - 1; i >= 0; i-- {
				res = append(res, r[i])
			}
			matrix = matrix[:len(matrix)-1]
		}

		// first column
		for i := len(matrix) - 1; i >= 0; i-- {
			if len(matrix[i]) > 0 {
				res = append(res, matrix[i][0])
				matrix[i] = matrix[i][1:]
			}
		}
	}
	return res
}

func main() {
	matrix := [][]int{}
	fmt.Println(spiralOrder(matrix))

	matrix = [][]int{{0, 1, 2, 3},}
	fmt.Println(spiralOrder(matrix))

	matrix = [][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9},}
	fmt.Println(spiralOrder(matrix))

	matrix = [][]int{{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}}
	//matrix = [][]int{{1}, {2}, {3}, {4}}
	fmt.Println(spiralOrder(matrix))
}
