package main

import (
	"fmt"
)

// The gray code is a binary numeral system where two successive values differ in only one bit.

// Given a non-negative integer n representing the total number of bits in the code, print the
// sequence of gray code. A gray code sequence must begin with 0.
//
// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
//
// Note:
// For a given n, a gray code sequence is not uniquely defined.
//
// For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
//
// For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

// Runtime: 12 ms, 31%
func grayCode(n int) []int {
	if n == 0 {
		return []int{0}
	}
	l := grayCode(n - 1)
	r := make([]int, len(l))
	for i := 0; i < len(l); i++ {
		r[i] = l[len(l)-i-1] + (1 << uint(n-1))
	}
	return append(l, r...)
}

// holy shit, clever
func grayCode2(n int) []int {
	var array []int
	m := uint(n)
	for i := 0; i < (1 << m); i++ {
		array = append(array, i)
		array[i] = array[i] ^ (array[i] >> 1)
	}
	return array
}

func main() {
	fmt.Println(grayCode(0))
	fmt.Println(grayCode(1))
	fmt.Println(grayCode(2))
	fmt.Println(grayCode(3))

	fmt.Println(grayCode2(0))
	fmt.Println(grayCode2(1))
	fmt.Println(grayCode2(2))
	fmt.Println(grayCode2(3))
}
