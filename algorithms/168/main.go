package main

import (
	"bytes"
	"fmt"
)

// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
// For example:
//
// 1 -> A
// 2 -> B
// 3 -> C
// ...
// 26 -> Z
// 27 -> AA
// 28 -> AB

// shit !
func convertToTitle(n int) string {
	var buf bytes.Buffer
	var stack []int

	for n != 0 {
		stack = append(stack, n%26)
		if n%26 == 0 {
			n /= 27
		} else {
			n /= 26
		}
	}

	for i := len(stack) - 1; i >= 0; i-- {
		if stack[i] == 0 {
			buf.WriteByte('Z')
		} else {
			buf.WriteByte('A' + byte(stack[i]) - 1)
		}
	}
	return buf.String()
}

func convertToTitle2(n int) string {
	k := "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

	result := ""
	for n > 0 {
		result = string(k[(n-1)%26]) + result
		n = (n - 1) / 26
	}
	return result
}

func main() {
	fmt.Println(convertToTitle(26))
	fmt.Println(convertToTitle(27))
	fmt.Println(convertToTitle(28))
	fmt.Println(convertToTitle(29))
	fmt.Println(convertToTitle(51))
	fmt.Println(convertToTitle(52))
	fmt.Println(convertToTitle(53))

	fmt.Println(convertToTitle2(26))
	fmt.Println(convertToTitle2(27))
	fmt.Println(convertToTitle2(28))
	fmt.Println(convertToTitle2(29))
	fmt.Println(convertToTitle2(51))
	fmt.Println(convertToTitle2(52))
	fmt.Println(convertToTitle2(53))
}
