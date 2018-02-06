package main

import "fmt"

// There are a total of n courses you have to take, labeled from 0 to n - 1.
//
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1,
// which is expressed as a pair: [0,1]
//
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
//
// For example:
//
// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
//
// 2, [[1,0],[0,1]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take
// course 0 you should also have finished course 1. So it is impossible.
//
// Note:
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
// Read more about how a graph is represented.
//
// You may assume that there are no duplicate edges in the input prerequisites.
//
// Hints:
// This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological
// ordering exists and therefore it will be impossible to take all courses.
// Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of
// Topological Sort.
// Topological sort could also be done via BFS.

// Runtime: 35 ms, 51.61%
func canFinish(numCourses int, prerequisites [][]int) bool {
	var graph = make(map[int][]int)
	for _, pair := range prerequisites {
		i, j := pair[0], pair[1]
		graph[i] = append(graph[i], j)
	}
	// stack: record all unfinished class
	stack := make(map[int]bool)
	seen := make(map[int]bool)

	var loop = true
	// dfs
	var dfs func(i int)
	dfs = func(i int) {
		seen[i] = true
		stack[i] = true
		for _, j := range graph[i] {
			if !seen[j] {
				dfs(j)
			} else {
				if stack[j] {
					loop = false
				}
			}
		}
		stack[i] = false
	}
	for i := 0; i < numCourses; i++ {
		if !seen[i] {
			dfs(i)
		}
	}
	return loop
}

func main() {
	fmt.Println(canFinish(2, [][]int{{1, 0}}))
	fmt.Println(canFinish(2, [][]int{{1, 0}, {0, 1}}))
}
