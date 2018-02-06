package main

import "fmt"

/*
	Given a binary tree, determine if it is height-balanced.

	For this problem, a height-balanced binary tree is defined as a binary tree in
	which the depth of the two subtrees of every node never differ by more than 1.
*/

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func Height(t *TreeNode) int {
	if t == nil {
		return -1
	}
	return max(Height(t.Left), Height(t.Right)) + 1
}

// 29ms, 8.33% ...
func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}

	if isBalanced(root.Left) && isBalanced(root.Right) {
		l := Height(root.Left)
		r := Height(root.Right)

		if l > r {
			return l-r <= 1
		}
		return r-l <= 1
	}
	return false
}

func main() {
	tree1 := &TreeNode{1,
		&TreeNode{0,
			&TreeNode{-1, nil, nil}, nil},
		&TreeNode{2, nil, nil}}
	fmt.Println(isBalanced(tree1))
}
