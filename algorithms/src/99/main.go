package main

import (
	"fmt"
	"strings"
)

/**
	Two elements of a binary search tree (BST) are swapped by mistake.
	Recover the tree without changing its structure.

	Note:
	A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 */

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// first: implement the O(n) straight forward method
// 52ms, 30%
func recoverTree(root *TreeNode) {
	var nodes []*TreeNode

	var walk func(*TreeNode)
	walk = func(n *TreeNode) {
		if n == nil {
			return
		}
		walk(n.Left)
		nodes = append(nodes, n)
		walk(n.Right)
	}
	walk(root)

	// find two mistaken node with two pointer
	var m, n int
	for i := 0; i < len(nodes)-1; i++ {
		if nodes[i].Val > nodes[i+1].Val {
			m = i
			break
		}
	}
	for j := len(nodes) - 1; j > 0; j-- {
		if nodes[j].Val < nodes[j-1].Val {
			n = j
			break
		}
	}

	// swap m,n node's Val
	tmp := nodes[m].Val
	nodes[m].Val = nodes[n].Val
	nodes[n].Val = tmp
}

// then it do better
func recoverTree2(root *TreeNode) {

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
	tree1 := &TreeNode{2, &TreeNode{3, nil, nil}, &TreeNode{1, nil, nil}}
	recoverTree(tree1)
	fmt.Println(tree1)

	tree4 := &TreeNode{10, &TreeNode{5, nil, nil}, &TreeNode{15, &TreeNode{6, nil, nil},
		&TreeNode{20, nil, nil}}}
	recoverTree(tree4)
	fmt.Println(tree4)
}
