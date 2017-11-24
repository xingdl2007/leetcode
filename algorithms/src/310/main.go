package main

import "fmt"

// For a undirected graph with tree characteristics, we can choose any node as the root.
// The result graph is then a rooted tree. Among all possible rooted trees, those with
// minimum height are called minimum height trees (MHTs). Given such a graph, write a
// function to find all the MHTs and return a list of their root labels.
//
// Format
// The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number
// n and a list of undirected edges (each edge is a pair of labels).
//
// You can assume that no duplicate edges will appear in edges. Since all edges are undirected,
// [0, 1] is the same as [1, 0] and thus will not appear together in edges.
//
// Example 1:
//
// Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
//   0
//   |
//   1
//  / \
// 2   3
// return [1]
//
// Example 2:
//
// Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
//
// 0  1  2
//  \ | /
// 	  3
//    |
//    4
//    |
//    5
// return [3, 4]
//
// Note:
//
// (1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in
// which any two vertices are connected by exactly one path. In other words, any connected
// graph without simple cycles is a tree.”
//
// (2) The height of a rooted tree is the number of edges on the longest downward path between
// the root and a leaf.

// brute force: time limit exceeded
func findMinHeightTrees(n int, edges [][]int) []int {
	var graph = make(map[int][]int)
	for _, edge := range edges {
		graph[edge[0]] = append(graph[edge[0]], edge[1])
		graph[edge[1]] = append(graph[edge[1]], edge[0])
	}
	var height = n
	var record = make(map[int]int)
	var roots []int

	// return height rooted at i
	var dfs func(i int, seen map[int]bool) int
	dfs = func(i int, seen map[int]bool) int {
		seen[i] = true
		var height = -1
		for _, j := range graph[i] {
			if !seen[j] {
				h := dfs(j, seen)
				if height < h {
					height = h
				}
			}
		}
		return height + 1
	}
	for i := 0; i < n; i++ {
		h := dfs(i, map[int]bool{})
		record[i] = h
		if h < height {
			height = h
		}
	}
	// min height
	for k, v := range record {
		if v == height {
			roots = append(roots, k)
		}
	}
	return roots
}

// try to do it better
// impressive!
// ref: leetcode
//
// Our problem want us to find the minimum height trees and return their root labels.
// First we can think about a simple case -- a path graph.
//
// For a path graph of n nodes, find the minimum height trees is trivial. Just designate the middle point(s) as roots.
// Despite its triviality, let design a algorithm to find them.
//
// Suppose we don't know n, nor do we have random access of the nodes. We have to traversal.
//
// It is very easy to get the idea of two pointers. One from each end and move at the same speed.
// When they meet or they are one step away, (depends on the parity of n), we have the roots we want.
//
// This gives us a lot of useful ideas to crack our real problem.
// For a tree we can do some thing similar. We start from every end, by end we mean vertex of degree 1 (aka leaves).
// We let the pointers move the same speed. When two pointers meet, we keep only one of them, until the last
//
// two pointers meet or one step away we then find the roots.
// It is easy to see that the last two pointers are from the two ends of the longest path in the graph.
//
// The actual implementation is similar to the BFS topological sort. Remove the leaves, update the degrees
// of inner vertexes. Then remove the new leaves. Doing so level by level until there are 2 or 1 nodes left.
// What's left is our answer!
//
// The time complexity and space complexity are both O(n).
//
// a bit like topological sort with BFS, source deletion

// Runtime: 122ms, a bit slow, map delete operation may be expensive,
// should be avoided if possible; and use space to trade time
func findMinHeightTrees2(n int, edges [][]int) []int {
	// If only 1 node, it is root.
	if n == 1 {
		return []int{0}
	}
	var graph = make(map[int]map[int]struct{})
	for i := 0; i < n; i++ {
		graph[i] = make(map[int]struct{})
	}
	for _, edge := range edges {
		i, j := edge[0], edge[1]
		graph[i][j] = struct{}{}
		graph[j][i] = struct{}{}
	}
	var leaves []int
	for k, v := range graph {
		if len(v) == 1 {
			leaves = append(leaves, k)
		}
	}
	// delete all leaves, then generate all new leaves
	// use space to trade time
	for n > 2 {
		n -= len(leaves)
		var newLeafs = make([]int, 0, len(leaves))
		for _, i := range leaves {
			for j := range graph[i] {
				// should delete, because of the len()
				delete(graph[j], i)
				if len(graph[j]) == 1 {
					newLeafs = append(newLeafs, j)
				}
			}
			// no need to delete,actually, good for debug
			delete(graph, i)
		}
		leaves = newLeafs
	}
	return leaves
}

// Implementation optimization
// Runtime: 72 ms, impressive!
func findMinHeightTrees3(n int, edges [][]int) []int {
	if n == 1 {
		return []int{0}
	}
	eMap := make([][]int, n)
	for i := 0; i < n; i++ {
		eMap[i] = make([]int, 0, 5)
	}
	degrees := make([]int, n)
	for _, e := range edges {
		eMap[e[0]] = append(eMap[e[0]], e[1])
		eMap[e[1]] = append(eMap[e[1]], e[0])
		degrees[e[0]]++
		degrees[e[1]]++
	}
	var leafs = make([]int, 0, n)
	var nd, leaf int
	for i := 0; i < n; i++ {
		if degrees[i] == 1 {
			leafs = append(leafs, i)
		}
	}
	for n > 2 {
		newLeafs := make([]int, 0, len(leafs))
		n -= len(leafs)
		for _, leaf = range leafs {
			for _, nd = range eMap[leaf] {
				degrees[nd]--
				if degrees[nd] == 1 {
					newLeafs = append(newLeafs, nd)
				}
			}
		}
		leafs = newLeafs
	}
	return leafs
}

func main() {
	fmt.Println(findMinHeightTrees(4, [][]int{{1, 0}, {1, 2}, {1, 3},}))
	fmt.Println(findMinHeightTrees(6, [][]int{{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}}))
	fmt.Println(findMinHeightTrees(1, [][]int{}))
	fmt.Println(findMinHeightTrees(3, [][]int{{0, 1}, {0, 2},}))

	// compare
	fmt.Println(findMinHeightTrees2(4, [][]int{{1, 0}, {1, 2}, {1, 3},}))
	fmt.Println(findMinHeightTrees2(6, [][]int{{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}}))
	fmt.Println(findMinHeightTrees2(1, [][]int{}))
	fmt.Println(findMinHeightTrees2(3, [][]int{{0, 1}, {0, 2},}))

	fmt.Println(findMinHeightTrees3(4, [][]int{{1, 0}, {1, 2}, {1, 3},}))
	fmt.Println(findMinHeightTrees3(6, [][]int{{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}}))
	fmt.Println(findMinHeightTrees3(1, [][]int{}))
	fmt.Println(findMinHeightTrees3(3, [][]int{{0, 1}, {0, 2},}))
}
