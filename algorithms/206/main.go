package main

import (
	"bytes"
	"strconv"
	"fmt"
)

// Reverse a singly linked list.
// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func (l *ListNode) String() string {
	var buf bytes.Buffer
	buf.WriteByte('[')

	for l != nil {
		buf.WriteString(strconv.Itoa(l.Val))
		l = l.Next
		buf.WriteByte(' ')
	}
	buf.WriteByte(']')
	return buf.String()
}

// recursive
// Runtime: 3ms
func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	last, cur := head, head.Next
	head.Next = nil
	for cur != nil {
		next := cur.Next
		cur.Next = last
		last, cur = cur, next
	}
	return last
}

func main() {
	l := &ListNode{1, nil}
	fmt.Println(reverseList(l))

	l = &ListNode{1, &ListNode{2, nil}}
	fmt.Println(reverseList(l))

	l = &ListNode{1, &ListNode{2, &ListNode{3, nil}}}
	fmt.Println(reverseList(l))
}
