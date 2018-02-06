package main

import (
	"fmt"
	"strings"
)

/**
	Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */

// apparently there are simpler solution, note: `sorted in ascending order`

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func (t *TreeNode) String() string {
	var nodes []string
	var walk func(*TreeNode)
	walk = func(n *TreeNode) {
		if n == nil {
			return
		}
		walk(n.Left)
		nodes = append(nodes, fmt.Sprintf("%d ", n.Val))
		walk(n.Right)
	}
	nodes = append(nodes, "[")
	walk(t)
	nodes = append(nodes, "]")
	return strings.Join(nodes, " ")
}

// ok
// balanced BST, AVL is overkill for sorted array
func sortedArrayToBST(nums []int) *TreeNode {
	var root *TreeNode

	if size := len(nums); size > 0 {
		root = &TreeNode{Val: nums[size/2]}
		root.Left = sortedArrayToBST(nums[:size/2])
		root.Right = sortedArrayToBST(nums[size/2+1:])
	}
	return root
}

func main() {
	array := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	fmt.Println(sortedArrayToBST(array))
}
