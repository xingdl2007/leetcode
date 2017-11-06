package main

import (
	"fmt"
	"strings"
	"math"
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
// 42ms, 76.92%
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
	nodes[m].Val, nodes[n].Val = nodes[n].Val, nodes[m].Val
}

// ref
var firstElement *TreeNode = nil
var secondElement *TreeNode = nil
var preElementVal *TreeNode = &TreeNode{Val: math.MinInt32}

func recoverTree2(root *TreeNode) {
	if nil == root {
		return
	}
	firstElement = nil
	secondElement = nil
	preElementVal = &TreeNode{Val: math.MinInt32}

	TraceTree(root)

	fmt.Println(firstElement.Val, secondElement.Val)
	firstElement.Val, secondElement.Val = secondElement.Val, firstElement.Val
}

func TraceTree(root *TreeNode) {
	if nil == root {
		return
	}
	TraceTree(root.Left)

	if nil == firstElement && preElementVal.Val >= root.Val {
		firstElement = preElementVal
	}
	if nil != firstElement && preElementVal.Val >= root.Val {
		secondElement = root
	}
	preElementVal = root

	TraceTree(root.Right)
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
	recoverTree2(tree1)
	fmt.Println(tree1)

	tree4 := &TreeNode{10, &TreeNode{5, nil, nil}, &TreeNode{15, &TreeNode{6, nil, nil},
		&TreeNode{20, nil, nil}}}
	fmt.Println(tree4)
	recoverTree(tree4)
	fmt.Println(tree4)

}
