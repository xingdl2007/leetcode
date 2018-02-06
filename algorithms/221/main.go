package main

import (
	"fmt"
)

// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
// For example, given the following matrix:
//
// 1 0 1 0 0
// 1 0 1-1 1
// 1 1 1-1 1
// 1 0 0 1 0
//
// Return 4.

type info struct {
	i, j  int
	valid int
}

// verbose version, not very elegant, but the method is easy to understand
// Runtime: 6 ms, 15%
func maximalSquare(matrix [][]byte) int {
	if len(matrix) == 0 {
		return 0
	}
	row, col := len(matrix), len(matrix[0])
	if col == 0 {
		return 0
	}

	var area = 0
	infos := make([][]info, row+1)
	for i := 0; i <= row; i++ {
		infos[i] = make([]info, col+1)
	}
	// the rest of matrix
	for i := 1; i <= row; i++ {
		for j := 1; j <= col; j++ {
			if matrix[i-1][j-1] == '1' {
				infos[i][j].i = 1 + infos[i][j-1].i
				infos[i][j].j = 1 + infos[i-1][j].j
				infos[i][j].valid = 1

				tmp := min(infos[i][j].i, infos[i][j].j)
				if infos[i-1][j-1].valid > 0 {
					if tmp >= infos[i-1][j-1].valid+1 {
						infos[i][j].valid = infos[i-1][j-1].valid + 1
					} else {
						infos[i][j].valid = tmp
					}
				}
				tmp = infos[i][j].valid * infos[i][j].valid
				if area < tmp {
					area = tmp
				}
			}
		}
	}
	return area
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// https://leetcode.com/articles/maximal-square/
// key: dp[i,j] = min(dp[i-1,j],dp[i-1,j-1],dp[i,j-1])+1

/*

// better solution:
public class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
        int[][] dp = new int[rows + 1][cols + 1];
        int maxsqlen = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i-1][j-1] == '1'){
                    dp[i][j] = Math.min(Math.min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    maxsqlen = Math.max(maxsqlen, dp[i][j]);
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
}

// too clever
public class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
        int[] dp = new int[cols + 1];
        int maxsqlen = 0, prev = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = Math.min(Math.min(dp[j - 1], prev), dp[j]) + 1;
                    maxsqlen = Math.max(maxsqlen, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return maxsqlen * maxsqlen;
    }
}
 */

func maximalSquare2(matrix [][]byte) int {
	if len(matrix) == 0 {
		return 0
	}
	row, col := len(matrix), len(matrix[0])
	if col == 0 {
		return 0
	}

	var side, prev = 0, 0
	dp := make([]int, col+1)

	for i := 1; i <= row; i++ {
		for j := 1; j <= col; j++ {
			tmp := dp[j]
			if matrix[i-1][j-1] == '1' {
				dp[j] = min(min(dp[j-1], dp[j]), prev) + 1
				side = max(side, dp[j])
			} else {
				dp[j] = 0
			}
			prev = tmp
		}
	}
	return side * side
}

func main() {
	matrix := [][]byte{
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'},
	}
	fmt.Println(maximalSquare(matrix))
	fmt.Println(maximalSquare2(matrix))

	matrix = [][]byte{{'1'},}
	fmt.Println(maximalSquare(matrix))
	fmt.Println(maximalSquare2(matrix))

	matrix = [][]byte{{'0', '1'},}
	fmt.Println(maximalSquare(matrix))
	fmt.Println(maximalSquare2(matrix))

	matrix = [][]byte{
		{'0', '0', '0', '1'},
		{'1', '1', '0', '1'},
		{'1', '1', '1', '1'},
		{'0', '1', '1', '1'},
		{'0', '1', '1', '1'},
	}
	fmt.Println(maximalSquare(matrix))
	fmt.Println(maximalSquare2(matrix))

	matrix = [][]byte{
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'},
	}
	fmt.Println(maximalSquare(matrix))
	fmt.Println(maximalSquare2(matrix))

}
