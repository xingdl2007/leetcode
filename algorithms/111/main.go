package main

import "fmt"

/*
	Given a binary tree, find its minimum depth.

	The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func compare(x, y int) int {
	if x == 0 {
		return y
	} else if y == 0 {
		return x
	}

	if x < y {
		return x
	}
	return y
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	if root.Left == nil && root.Right == nil {
		return 1
	}

	return compare(minDepth(root.Left), minDepth(root.Right)) + 1
}

func main() {
	tree1 := &TreeNode{1,
		&TreeNode{0,
			&TreeNode{-1, nil, nil}, nil},
		&TreeNode{2, nil, nil}}
	fmt.Println(minDepth(tree1))

	tree2 := &TreeNode{1, &TreeNode{2, nil, nil}, nil}
	fmt.Println(minDepth(tree2))

	fmt.Println(minDepth(nil))
}
