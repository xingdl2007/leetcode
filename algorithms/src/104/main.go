package main

import (
	"fmt"
)

/**
	Given a binary tree, find its maximum depth.
	The maximum depth is the number of nodes along the longest path
		from the root node down to the farthest leaf node.
 */

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 9ms, 72.67%
func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	ld := maxDepth(root.Left)
	rd := maxDepth(root.Right)

	if ld > rd {
		return ld + 1
	}
	return rd + 1
}

func main() {
	tree1 := &TreeNode{1, &TreeNode{2, nil, nil}, &TreeNode{3, nil, nil}}
	fmt.Println(maxDepth(tree1))

	tree4 := &TreeNode{10, &TreeNode{5, nil, nil},
		&TreeNode{15, &TreeNode{6, nil, nil},
			&TreeNode{20, nil, nil}}}

	fmt.Println(maxDepth(tree4))

	fmt.Println(maxDepth(nil))
}
