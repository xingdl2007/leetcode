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

// error-prone
// 12ms, 78.38%
// [] 0: false
func hasPathSum(root *TreeNode, sum int) bool {
	if root == nil {
		return false
	}

	// must be leaf node
	if root.Val == sum && root.Left == nil && root.Right == nil {
		return true
	}

	return hasPathSum(root.Left, sum-root.Val) || hasPathSum(root.Right, sum-root.Val)
}

func main() {
	tree1 := &TreeNode{1,
		&TreeNode{0,
			&TreeNode{-1, nil, nil}, nil},
		&TreeNode{2, nil, nil}}
	fmt.Println(hasPathSum(tree1, 3))

	tree2 := &TreeNode{1, &TreeNode{2, nil, nil}, nil}
	fmt.Println(hasPathSum(tree2, 1))

	fmt.Println(hasPathSum(nil, 0))
}
