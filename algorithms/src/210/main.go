package main

import "fmt"

// There are a total of n courses you have to take, labeled from 0 to n - 1.
//
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1,
// which is expressed as a pair: [0,1]
//
// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses
// you should take to finish all courses.
//
// There may be multiple correct orders, you just need to return one of them. If it is impossible to
// finish all courses, return an empty array.
//
// For example:
//
// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0.
// So the correct course order is [0,1]
//
// 4, [[1,0],[2,0],[3,1],[3,2]]
// There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2.
// Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3].
// Another correct ordering is[0,2,1,3].
//
// Note:
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
// Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.
// click to show more hints.
//
// Hints:
// This problem is equivalent to finding the topological order in a directed graph. If a cycle exists,
// no topological ordering exists and therefore it will be impossible to take all courses.
//
// Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
// Topological sort could also be done via BFS.

// Runtime: 36 ms, 53.85%
func findOrder(numCourses int, prerequisites [][]int) []int {
	var graph = make(map[int][]int)
	for _, pair := range prerequisites {
		i, j := pair[0], pair[1]
		graph[i] = append(graph[i], j)
	}
	// stack: record all unfinished class
	stack := make(map[int]bool)
	seen := make(map[int]bool)
	order := make([]int, 0, numCourses)

	var hasloop = false

	// dfs
	var dfs func(i int) bool
	dfs = func(i int) bool {
		seen[i] = true
		stack[i] = true
		for _, j := range graph[i] {
			if !seen[j] {
				// if has loop, return early
				if dfs(j) {
					return true
				}
			} else {
				if stack[j] {
					hasloop = true
					return true
				}
			}
		}
		stack[i] = false
		order = append(order, i)
		return false
	}
	for i := 0; i < numCourses; i++ {
		if !seen[i] && dfs(i) {
			return nil
		}
	}
	return order
}

func main() {
	fmt.Println(findOrder(2, [][]int{{1, 0}}))
	fmt.Println(findOrder(2, [][]int{{1, 0}, {0, 2}}))
}
