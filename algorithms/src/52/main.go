package main

import "fmt"

func totalNQueens(n int) int {
	res := make([]int, n, n)
	var count int
	for i := 0; i < len(res); i++ {
		res[i] = -1
	}

	for k := 0; k >= 0; k-- {
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
			count++
		}
	}
	return count
}

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

func main() {
	fmt.Println(totalNQueens(8))
}
