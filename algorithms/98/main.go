package main

import (
	"fmt"
	"math"
)

/**
	Given a binary tree, determine if it is a valid binary search tree (BST).

	Assume a BST is defined as follows:

	The left subtree of a node contains only nodes with keys less than the node's key.
	The right subtree of a node contains only nodes with keys greater than the node's key.
	Both the left and right subtrees must also be binary search trees.


	Example 1:
		2
	   / \
	  1   3
	Binary tree [2,1,3], return true.
	Example 2:
		1
	   / \
	  2   3
	Binary tree [1,2,3], return false.

 */

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// shit !
// 26ms, 12.82%  apparently not the best
func isValidBST(root *TreeNode) bool {
	var vals []int
	var walk func(*TreeNode)
	walk = func(node *TreeNode) {
		if node == nil {
			return
		}
		walk(node.Left)
		vals = append(vals, node.Val)
		walk(node.Right)
	}
	walk(root)

	// checking, strictly less than / greater than
	// can't use `sort.IntsAreSorted()`
	for i := 1; i < len(vals); i++ {
		if vals[i] <= vals[i-1] {
			return false
		}
	}
	return true
}

// interesting
// 22ms, 15%?
// why anonymous function is slower than named function?
func isValidBST2(root *TreeNode) bool {
	var walk func(*TreeNode, int, int, bool, bool) bool
	walk = func(node *TreeNode, min, max int, minFlag, maxFlag bool) bool {
		if node == nil {
			return true
		}
		if ( minFlag && node.Val <= min) || (maxFlag && node.Val >= max) {
			return false
		}
		return walk(node.Left, min, node.Val, minFlag, true) &&
			walk(node.Right, node.Val, max, true, maxFlag)
	}

	return walk(root, math.MinInt64, math.MaxInt64, false, false)
}

// 13ms, 90%
func isValidBST3(root *TreeNode) bool {
	return walk(root, math.MinInt64, math.MaxInt64, false, false)
}
func walk(node *TreeNode, min, max int, minFlag, maxFlag bool) bool {
	if node == nil {
		return true
	}
	if (minFlag && node.Val <= min) || (maxFlag && node.Val >= max) {
		return false
	}
	return walk(node.Left, min, node.Val, minFlag, true) &&
		walk(node.Right, node.Val, max, true, maxFlag)
}

func main() {
	tree1 := &TreeNode{2, &TreeNode{1, nil, nil}, &TreeNode{3, nil, nil}}
	fmt.Println(isValidBST3(tree1))

	tree2 := &TreeNode{1, &TreeNode{2, nil, nil}, &TreeNode{3, nil, nil}}
	fmt.Println(isValidBST3(tree2))

	tree3 := &TreeNode{1, &TreeNode{1, nil, nil}, nil}
	fmt.Println(isValidBST3(tree3))

	tree4 := &TreeNode{10, &TreeNode{5, nil, nil}, &TreeNode{15, &TreeNode{6, nil, nil},
		&TreeNode{20, nil, nil}}}
	fmt.Println(isValidBST3(tree4))
}
