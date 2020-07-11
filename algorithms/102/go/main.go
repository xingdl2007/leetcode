package main

import "fmt"

/*
	Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

	For example:
	Given binary tree [3,9,20,null,null,15,7],
		3
	   / \
	  9  20
		/  \
	   15   7
	return its level order traversal as:
	[
	  [3],
	  [9,20],
	  [15,7]
	]
*/

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func pingPong(ping, pong *[]*TreeNode) (level []int) {
	for _, node := range *ping {
		level = append(level, node.Val)
		if node.Left != nil {
			*pong = append(*pong, node.Left)
		}
		if node.Right != nil {
			*pong = append(*pong, node.Right)
		}
	}
	// clear element
	*ping = (*ping)[:0]
	return level
}

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}

	var res [][]int
	var ping, pong []*TreeNode
	// put root in ping buf, kick it start
	ping = append(ping, root)
	isPing := true
	for len(ping) > 0 || len(pong) > 0 {
		var level []int
		if isPing {
			isPing = false
			level = pingPong(&ping, &pong)
		} else {
			isPing = true
			level = pingPong(&pong, &ping)
		}
		res = append(res, level)
	}
	return res
}

func main() {
	//[3,9,20,null,null,15,7]
	tree := &TreeNode{3, &TreeNode{9, nil, nil},
		&TreeNode{20, &TreeNode{15, nil, nil},
			&TreeNode{7, nil, nil}}}
	fmt.Println(levelOrder(tree))
}
