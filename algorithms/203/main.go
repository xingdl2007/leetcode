package main

import (
	"bytes"
	"fmt"
)

// Remove all elements from a linked list of integers that have value val.
//
// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5

//Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func (l *ListNode) String() string {
	var buf bytes.Buffer
	buf.WriteByte('[')
	for l != nil {
		buf.WriteString(fmt.Sprintf("%d ", l.Val))
		l = l.Next
	}
	if buf.Len() > len("[") {
		buf.Truncate(buf.Len() - 1)
	}
	buf.WriteByte(']')
	return buf.String()
}

func removeElements(head *ListNode, val int) *ListNode {
	for head != nil && head.Val == val {
		head = head.Next
	}
	p := head
	for p != nil {
		// must be loop, little trick, in case of successive match
		for p.Next != nil && p.Next.Val == val {
			p.Next = p.Next.Next
		}
		p = p.Next
	}
	return head
}

func main() {
	// nil list
	fmt.Println(removeElements(nil, 6))

	l := &ListNode{6, nil}
	fmt.Println(removeElements(l, 6))

	l = &ListNode{6, &ListNode{3, &ListNode{6, nil}}}
	fmt.Println(removeElements(l, 6))

	l = &ListNode{3, &ListNode{6, &ListNode{6, nil}}}
	fmt.Println(removeElements(l, 6))

	l = &ListNode{6, &ListNode{5, &ListNode{6, nil}}}
	fmt.Println(removeElements(l, 3))
	fmt.Println(removeElements(l, 5))

	l = &ListNode{1, &ListNode{2, &ListNode{6, &ListNode{3,
		&ListNode{4, &ListNode{5, &ListNode{6, nil}}}}}}}
	fmt.Println(removeElements(l, 6))
}
