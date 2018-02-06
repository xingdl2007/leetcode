package main

import "fmt"

//Write a function that takes a string as input and returns the string reversed.
//
//Example:
//Given s = "hello", return "olleh".

func reverseString(s string) string {
	b := []byte(s)
	for i, j := 0, len(b)-1; i < j; {
		b[i], b[j] = b[j], b[i]
		i++
		j--
	}
	return string(b)
}

func main() {
	fmt.Println(reverseString("hello"))
}
