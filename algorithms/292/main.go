package main

import "fmt"

// You are playing the following Nim Game with your friend: There is a heap of stones
// on the table, each time one of you take turns to remove 1 to 3 stones. The one who
// removes the last stone will be the winner. You will take the first turn to remove the stones.

// Both of you are very clever and have optimal strategies for the game. Write a function
// to determine whether you can win the game given the number of stones in the heap.

// For example, if there are 4 stones in the heap, then you will never win the game:
// no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.

// see: Introduction to The Design and Analysis of Algorithms, p.127
func canWinNim(n int) bool {
	return n%4 != 0
}

func main() {
	fmt.Println(canWinNim(1))
	fmt.Println(canWinNim(2))
	fmt.Println(canWinNim(3))
	fmt.Println(canWinNim(4))
	fmt.Println(canWinNim(5))
	fmt.Println(canWinNim(6))
	fmt.Println(canWinNim(7))
}
