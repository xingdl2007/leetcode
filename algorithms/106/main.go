package main

import (
	"fmt"
	"strings"
)

/**
	Given inorder and postorder traversal of a tree, construct the binary tree.
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

// 49ms, 30%
func buildTree(inorder []int, postorder []int) *TreeNode {
	// build root
	var root *TreeNode
	if len(postorder) > 0 {
		root = new(TreeNode)
		root.Val = postorder[len(postorder)-1]

		var i int
		for i = 0; i < len(inorder); i++ {
			if inorder[i] == root.Val {
				break
			}
		}
		// build left-subtree
		root.Left = buildTree(inorder[0:i], postorder[0:i])
		// build right-subtree
		root.Right = buildTree(inorder[i+1:], postorder[i:len(postorder)-1])
	}
	return root
}

func main() {
	inorder := []int{5, 6, 10, 15, 20}
	postorder := []int{5, 10, 20, 15, 6}

	fmt.Println(buildTree(inorder, postorder))
}
