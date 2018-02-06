package main

import (
	"fmt"
	"strings"
)

/**
	Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */

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
		nodes = append(nodes, fmt.Sprintf("%d[%d:%d] ", n.Val, Height(n), BalanceFactor(n)))
		walk(n.Right)
	}
	nodes = append(nodes, "[")
	walk(t)
	nodes = append(nodes, "]")
	return strings.Join(nodes, " ")
}

func BalanceFactor(t *TreeNode) int {
	if t == nil {
		return 0
	}
	return Height(t.Left) - Height(t.Right)
}

func Height(t *TreeNode) int {
	if t == nil {
		return -1
	}
	return max(Height(t.Left), Height(t.Right)) + 1
}

// helper function
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func put(t *TreeNode, val int) *TreeNode {
	if t == nil {
		return &TreeNode{Val: val}
	}
	if val < t.Val {
		t.Left = put(t.Left, val)
	} else {
		t.Right = put(t.Right, val)
	}

	// reBalance if put break AVL invariant
	// t is the nearest node
	if BalanceFactor(t) == 2 || BalanceFactor(t) == -2 {
		if val < t.Val {
			// R or RL
			if BalanceFactor(t.Left) == 1 {
				// R
				t = rRotation(t)
			} else {
				// RL
				t = rlRotation(t)
			}
		} else {
			// L or LR
			if BalanceFactor(t.Right) == -1 {
				// L
				t = lRotation(t)
			} else {
				// LR
				t = lrRotation(t)
			}
		}
	}
	return t
}

func rRotation(t *TreeNode) *TreeNode {
	c := t.Left
	t.Left = c.Right
	c.Right = t

	return c
}

func lRotation(t *TreeNode) *TreeNode {
	c := t.Right
	t.Right = c.Left
	c.Left = t

	return c
}

func rlRotation(r *TreeNode) *TreeNode {
	c := r.Left
	g := c.Right

	c.Right = g.Left
	r.Left = g.Right

	g.Left = c
	g.Right = r

	return g
}

func lrRotation(l *TreeNode) *TreeNode {
	c := l.Right
	g := c.Left

	c.Left = g.Right
	l.Right = g.Left

	g.Right = c
	g.Left = l

	return g
}

// balanced BST
// AVL-method 31/32 passed, last one time limit exceeded
func sortedArrayToBST(nums []int) *TreeNode {
	var root *TreeNode
	for _, n := range nums {
		root = put(root, n)
	}
	return root
}

func main() {
	array := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	fmt.Println(sortedArrayToBST(array))
}
