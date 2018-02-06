package main

import "fmt"

// Related to question Excel Sheet Column Title
//
// Given a column title as appear in an Excel sheet, return its corresponding column number.
//
// For example:
//
// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28

func titleToNumber(s string) int {
	var n int
	for i := 0; i < len(s); i++ {
		n = n*26 + int(s[i]-'A'+1)
	}
	return n
}

func main() {
	fmt.Println(titleToNumber("AZ"))
}
