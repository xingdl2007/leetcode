package main

import (
	"bytes"
	"fmt"
)

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val  int
	Next *ListNode
}

// mergeKLists() merge k sorted linked lists and return it as one sorted list.
// Analyze and describe its complexity.

// Merge with Divide And Conquer
// Runtime: 15 ms, 100%, are you kidding me?
func mergeKLists(lists []*ListNode) *ListNode {
	count := len(lists)
	if count == 0 {
		return nil
	} else if count == 1 {
		return lists[0]
	}
	return merge(mergeKLists(lists[0:count/2]), mergeKLists(lists[count/2:]))
}

// merge() merge two listNode
func merge(l *ListNode, r *ListNode) *ListNode {
	if l == nil {
		return r
	}
	if r == nil {
		return l
	}

	head := l
	if r.Val < l.Val {
		head = r
		r = r.Next
	} else {
		l = l.Next
	}
	tail := head

	for l != nil || r != nil {
		if l == nil {
			tail.Next = r
			r = nil
			break
		}
		if r == nil {
			tail.Next = l
			l = nil
			break
		}

		if l.Val <= r.Val {
			tail.Next = l
			l = l.Next
		} else {
			tail.Next = r
			r = r.Next
		}
		tail = tail.Next
	}

	return head
}

func NewNode(val int, nxt *ListNode) *ListNode {
	return &ListNode{
		Val:  val,
		Next: nxt,
	}
}

func (head *ListNode) String() string {
	if head == nil {
		return "[]"
	}

	buf := new(bytes.Buffer)
	buf.WriteByte('[')
	for head != nil {
		buf.WriteString(fmt.Sprintf("%d ", head.Val))
		head = head.Next
	}
	buf.Truncate(buf.Len() - 1)
	buf.WriteByte(']')
	return buf.String()
}

func main() {
	l := NewNode(5, NewNode(7, NewNode(10, nil)))
	r := NewNode(1, NewNode(5, NewNode(12, nil)))

	//fmt.Println(l)
	//fmt.Println(r)
	//fmt.Println(merge(l, r))

	m := []*ListNode{l, r}
	fmt.Println(mergeKLists(m))
}
