/*
	The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



	Given an integer n, return all distinct solutions to the n-queens puzzle.

	Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

	For example,
	There exist two distinct solutions to the 4-queens puzzle:

	[
	 [".Q..",  // Solution 1
	  "...Q",
	  "Q...",
	  "..Q."],

	 ["..Q.",  // Solution 2
	  "Q...",
	  "...Q",
	  ".Q.."]
	]
 */

package main

import (
	"bytes"
	"fmt"
)

// invalid: false
// O(n): i=> row, res[i]=> column
func isValid(res []int, k int) bool {
	for i := 0; i < k; i++ {
		if res[i] == res[k] ||
			i+res[i] == k+res[k] ||
			i-res[i] == k-res[k] {
			return false
		}
	}
	return true
}

func solution(n []int) (ret []string) {
	var buf bytes.Buffer
	for i := 0; i < len(n); i++ {
		for j := 0; j < len(n); j++ {
			if n[i] == j {
				buf.WriteByte('Q')
			} else {
				buf.WriteByte('.')
			}
		}
		ret = append(ret, buf.String())
		buf.Truncate(0)
	}
	return
}

// Runtime: 12 ms, 91.67%
func solveNQueens(n int) [][]string {
	res := make([]int, n, n)
	var ret [][]string
	for i := 0; i < len(res); i++ {
		res[i] = -1
	}

	for k := 0; k >= 0; {
		// find one solution
		for k != n && k >= 0 {
			res[k]++
			// subtle: backtrace
			if res[k] == n {
				res[k] = -1
				k--
				continue
			}
			if isValid(res[:], k) {
				k++
			}
		}
		// construct solutions
		if k == n {
			ret = append(ret, solution(res))

			// minor optimization
			res[k-1] = -1
			// restart start from last but one
			k -= 2
		}
	}
	return ret
}

func main() {
	fmt.Println(solveNQueens(4))
}
