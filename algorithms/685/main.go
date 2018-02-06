package main

import (
	"fmt"
)

// In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root)
// for which all other nodes are descendants of this node, plus every node has exactly one parent,
// except for the root node which has no parents.
//
// The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N),
// with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not
// an edge that already existed.
//
// The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a
// directed edge connecting nodes u and v, where u is a parent of child v.
//
// Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple
// answers, return the answer that occurs last in the given 2D-array.
//
// Example 1:
// Input: [[1,2], [1,3], [2,3]]
//
// Output: [2,3]
// Explanation: The given directed graph will be like this:
//    1
//   / \
//  v   v
//  2-->3
//
// Example 2:
// Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
//
// Output: [4,1]
// Explanation: The given directed graph will be like this:
// 5 <- 1 -> 2
//      ^    |
//      |    v
//      4 <- 3
//
// Note:
// The size of the input 2D-array will be between 3 and 1000.
// Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

// 9ms, 100% !!
func findRedundantDirectedConnection(edges [][]int) []int {
	if len(edges) == 0 {
		return nil
	}
	N := len(edges)
	parent := make([]int, N)

	for i := range parent {
		parent[i] = i + 1
	}
	var ret = make([]int, 2)
	var c1, c2, c3 int
	var loop, twoParents bool

	for _, edge := range edges {
		p, c := edge[0], edge[1]
		if parent[c-1] == c {
			parent[c-1] = p

			// loop detection, got a loop, the last edge may be the result
			tmp := p
			if !loop {
				for parent[tmp-1] != tmp {
					tmp = parent[tmp-1]
					if tmp == c {
						ret[0], ret[1] = p, c
						loop = true
						break
					}
				}
			}
		} else {
			twoParents = true

			// when a node have two parents, must cut one of them
			// so got two candidates
			// Note: no update of parent
			c1 = parent[c-1]

			// c2 is latter, so if c1 and c2 are even, c2 is prefer
			c2 = p
			c3 = c
		}
	}

	// situation which a node have two parents, if not, just return the last edge of loop
	if twoParents {
		// is c1 in a loop? if so, c1 is prefer, since loop must be cut
		if loop {
			ret[0] = c1
		} else {
			ret[0] = c2
		}
		ret[1] = c3
	}
	return ret
}

func main() {
	edges := [][]int{
		{2, 1}, {3, 1}, {4, 2}, {1, 4},
	}
	fmt.Println(findRedundantDirectedConnection(edges))

	edges = [][]int{
		{1, 2}, {1, 3}, {2, 3},
	}
	fmt.Println(findRedundantDirectedConnection(edges))

	edges = [][]int{
		{2, 3}, {3, 4}, {1, 5}, {1, 2}, {4, 1},
	}
	fmt.Println(findRedundantDirectedConnection(edges))

	edges = [][]int{
		{5, 2}, {5, 1}, {3, 1}, {3, 4}, {3, 5},
	}
	fmt.Println(findRedundantDirectedConnection(edges))
}
