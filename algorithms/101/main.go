package main

import (
	"fmt"
	"strings"
)

/**
	Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

	For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

		1
	   / \
	  2   2
	 / \ / \
	3  4 4  3
	But the following [1,2,2,null,3,null,3] is not:
		1
	   / \
	  2   2
	   \   \
	   3    3
	Note:
	Bonus points if you could solve it both recursively and iteratively.
 */

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// recursive solution
// Oops..., interesting
// 6ms, 20%
func isSymmetric(root *TreeNode) bool {
	return isSymme(root, root)
}

func isSymme(left, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	}
	if left == nil || right == nil {
		return false
	}
	return left.Val == right.Val && isSymme(left.Left, right.Right) &&
		isSymme(left.Right, right.Left)
}

// iterative
func isSymmetric2(root *TreeNode) bool {
	return false
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

func main() {
	tree1 := &TreeNode{1,
		&TreeNode{2, nil, nil},
		&TreeNode{2, nil, nil}}
	fmt.Println(isSymmetric(tree1))

	tree2 := &TreeNode{1,
		&TreeNode{2,
			&TreeNode{3, nil, nil}, nil},
		&TreeNode{3,
			&TreeNode{2, nil, nil}, nil}}
	fmt.Println(tree2)
	fmt.Println(isSymmetric(tree2))
}
