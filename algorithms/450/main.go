package main

import (
	"bytes"
	"strconv"
	"fmt"
)

// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:
//
// Search for a node to remove.
// If the node is found, delete the node.
// Note: Time complexity should be O(height of tree).
//
// Example:
//
// root = [5,3,6,2,4,null,7]
// key = 3
//
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Given key to delete is 3. So we find the node with value 3 and delete it.
//
// One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
//
//     5
//    / \
//   4   6
//  /     \
// 2       7
//
// Another valid answer is [5,2,6,null,4,null,7].
//
//    5
//   / \
//  2   6
//   \   \
//    4   7

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func min(root *TreeNode) *TreeNode {
	if root.Left == nil {
		return root
	}
	return min(root.Left)
}

func deleteNode(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return nil
	}
	if key < root.Val {
		root.Left = deleteNode(root.Left, key)
	} else if key > root.Val {
		root.Right = deleteNode(root.Right, key)
	} else {
		if root.Left == nil {
			return root.Right
		}
		if root.Right == nil {
			return root.Left
		}
		x := min(root.Right)
		x.Right = deleteNode(root.Right, x.Val)
		x.Left = root.Left
		return x
	}
	return root
}

// binary search tree property validation
func (t *TreeNode) Check() bool {
	if t == nil {
		return true
	}
	if t.Left != nil && t.Left.Val >= t.Val {
		return false
	}
	if t.Right != nil && t.Right.Val < t.Val {
		return false
	}
	return t.Left.Check() && t.Right.Check()
}

func (t *TreeNode) Print(prefix string, isTail bool) string {
	if t == nil {
		return ""
	}
	var buf bytes.Buffer
	var addition1, addition2 string
	if isTail {
		addition1 = "└── "
		addition2 = "    "
	} else {
		addition1 = "├── "
		addition2 = "│   "
	}
	buf.WriteString(prefix + addition1 + strconv.Itoa(t.Val) + "\n")

	// left node is tail if there is no right node
	if t.Right != nil {
		isTail = false
	} else {
		isTail = true
	}
	buf.WriteString(t.Left.Print(prefix+addition2, isTail))
	// right node is always the tail
	buf.WriteString(t.Right.Print(prefix+addition2, true))
	return buf.String()
}

func (t *TreeNode) String() string {
	return t.Print("", true)
}

func main() {
	tree := &TreeNode{5, &TreeNode{3, nil, nil},
		&TreeNode{6, nil, nil}}
	fmt.Println(tree)

	tree = deleteNode(tree, 5)
	fmt.Println(tree)
}
