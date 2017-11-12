package main

import "fmt"

/*
	Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

	Example 1:
	Input:
		3
	   / \
	  9  20
		/  \
	   15   7
	Output: [3, 14.5, 11]
	Explanation:
	The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
 */

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func pingPong(ping, pong *[]*TreeNode) (average float64) {
	var level []int
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

	var sum float64
	for _, v := range level {
		sum += float64(v)
	}

	return sum / float64(len(level))
}

func averageOfLevels(root *TreeNode) []float64 {
	if root == nil {
		return nil
	}

	var res []float64
	var ping, pong []*TreeNode
	// put root in ping buf, kick it start
	ping = append(ping, root)
	isPing := true
	for len(ping) > 0 || len(pong) > 0 {
		var average float64
		if isPing {
			isPing = false
			average = pingPong(&ping, &pong)
		} else {
			isPing = true
			average = pingPong(&pong, &ping)
		}
		res = append(res, average)
	}

	return res
}

func main() {
	//[3,9,20,null,null,15,7]
	tree := &TreeNode{3, &TreeNode{9, nil, nil},
		&TreeNode{20, &TreeNode{15, nil, nil},
			&TreeNode{7, nil, nil}}}
	fmt.Println(averageOfLevels(tree))
}
