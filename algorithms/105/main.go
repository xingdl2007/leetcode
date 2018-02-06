package main

import (
	"fmt"
	"strings"
)

/**
	Given preorder and inorder traversal of a tree, construct the binary tree.
	Note: You may assume that duplicates do not exist in the tree.
 */

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func (root *TreeNode) String() string {
	var nodes []string
	var walk func(*TreeNode)
	walk = func(n *TreeNode) {
		if n == nil {
			return
		}
		walk(n.Left)
		nodes = append(nodes, fmt.Sprintf("%d", n.Val))
		walk(n.Right)
	}
	nodes = append(nodes, "[")
	walk(root)
	nodes = append(nodes, "]")

	return strings.Join(nodes, " ")
}

// 49ms, 42.86%
func buildTree(preorder []int, inorder []int) *TreeNode {
	// build root
	var root *TreeNode
	if len(preorder) > 0 {
		root = new(TreeNode)
		root.Val = preorder[0]

		var i int
		for i = 0; i < len(inorder); i++ {
			if inorder[i] == root.Val {
				break
			}
		}
		// build left-subtree
		root.Left = buildTree(preorder[1:i+1], inorder[0:i])
		// build right-subtree
		root.Right = buildTree(preorder[i+1:], inorder[i+1:])
	}
	return root
}

func main() {
	preorder := []int{6, 5, 15, 10, 20}
	inorder := []int{5, 6, 10, 15, 20}
	fmt.Println(buildTree(preorder, inorder))
}
