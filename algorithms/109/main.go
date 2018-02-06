package main

import (
	"fmt"
	"strings"
)

/**
   Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */

//Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

//Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sortedListNToBST(head *ListNode, length int) *TreeNode {
	var root *TreeNode
	if length > 0 {
		middle := head
		size := length / 2
		for i := size; i > 0; i-- {
			middle = middle.Next
		}
		root = new(TreeNode)
		root.Val = middle.Val
		root.Left = sortedListNToBST(head, size)
		root.Right = sortedListNToBST(middle.Next, length-size-1)
	}
	return root
}

// 2252ms, 2% shit
// difference is if you can modify original list
// if you can, length is not necessary
// if you can't, you need a length
func sortedListToBST(head *ListNode) *TreeNode {
	var length int
	probe := head
	for probe != nil {
		length++
		probe = probe.Next
	}
	return sortedListNToBST(head, length)
}

// modify original list
func sortedListToBST2(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}
	if head.Next == nil {
		return &TreeNode{Val: head.Val}
	}

	// find middle
	probe := head
	length := 0
	for probe.Next != nil {
		probe = probe.Next
		length++
	}

	half := length / 2
	probe = head
	for half > 1 {
		half--
		probe = probe.Next
	}
	middle := probe.Next
	probe.Next = nil

	return &TreeNode{
		Val:   middle.Val,
		Left:  sortedListToBST2(head),
		Right: sortedListToBST2(middle.Next),
	}
}

// 1392ms, 52%, ok
// another method, speedup only traverse list once, nice trick
func sortedListToBST3(head *ListNode) *TreeNode {
	// three common cases
	if head == nil {
		return nil
	}
	if head.Next == nil {
		return &TreeNode{Val: head.Val}
	}
	if head.Next != nil && head.Next.Next == nil {
		return &TreeNode{Val: head.Val,
			Right: &TreeNode{Val: head.Next.Val}}
	}

	pre, normal, double := head, head, head
	for double.Next != nil && double.Next.Next != nil {
		pre, normal = normal, normal.Next
		double = double.Next.Next
	}
	pre.Next = nil

	return &TreeNode{
		Val:   normal.Val,
		Left:  sortedListToBST3(head),
		Right: sortedListToBST3(normal.Next),
	}
}

func main() {
	list := &ListNode{1, &ListNode{2, &ListNode{3, nil}}}
	fmt.Println(sortedListToBST3(list))
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
