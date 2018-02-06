package main

import (
	"sort"
	"fmt"
)

// Find the kth largest element in an unsorted array. Note that it is the kth
// largest element in the sorted order, not the kth distinct element.
//
// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.
//
// Note:
// You may assume k is always valid, 1 ≤ k ≤ array's length.

// Runtime: 13 ms, 86.67% holy shit
// cheat
func findKthLargest(nums []int, k int) int {
	sort.Ints(nums)
	return nums[len(nums)-k]
}

// heap based solution: min heap
// Runtime: 12 ms, 96.67%
func findKthLargest2(nums []int, k int) int {
	heap := MinHeap(nums, k)
	fmt.Println(heap)
	for i := k; i < len(nums); i++ {
		// find a candidate
		if nums[i] > heap[1] {
			SetTop(heap, nums[i])
			fmt.Printf("%d %v\n", i, heap);
		}
	}
	fmt.Println(heap)
	return heap[1]
}

func SetTop(heap []int, can int) {
	heap[1] = can
	k := len(heap)
	// keep heap property
	for done, i := false, 1; !done && 2*i < k; {
		j := 2 * i
		if j+1 < k && heap[j+1] < heap[j] {
			j = j + 1
		}
		if heap[i] < heap[j] {
			done = true
		} else {
			// swap
			tmp := heap[i]
			heap[i] = heap[j]
			heap[j] = tmp
			i = j
		}
	}
}

// need extra space
func MinHeap(nums []int, n int) []int {
	// heap[0] is unused for implementation simplicity
	heap := make([]int, n+1, n+1)
	copy(heap[1:], nums[0:n])

	// bottom-up
	for i := n / 2; i > 0; i-- {
		k := i // k is necessary
		v := heap[k]

		for done := false; !done && 2*k <= n; {
			j := 2 * k
			// find smaller child
			if j+1 <= n && heap[j+1] < heap[j] {
				j = j + 1
			}
			// heap property
			if v > heap[j] {
				// swap child and parent
				heap[k] = heap[j]
				k = j
				heap[k] = v
			} else {
				done = true
			}
		}
	}
	return heap
}

// Construct in-place maxHeap with bottom up method
// same as minHeap, assume index start from 1, but use index-1 to access slice item
func MaxHeap(nums []int) []int {
	n := len(nums)
	for i := n / 2; i > 0; i-- {
		k := i
		v := nums[k-1]

		// child
		for done := false; !done && 2*k <= n; {
			j := 2 * k
			if j+1 <= n && nums[j-1] < nums[j] {
				j = j + 1
			}
			if v < nums[j-1] {
				//swap
				nums[k-1] = nums[j-1]
				k = j
				nums[k-1] = v
			} else {
				done = true
			}
		}
	}
	return nums
}

//Runtime: 12 ms, 96.67%
func findKthLargest4(nums []int, k int) int {
	heap := MaxHeap(nums)

	// swap head with tail, reduce heap size and keep heap property
	for i := 1; i < k; i++ {
		size := len(heap)
		heap[0] = heap[size-1]
		heap = heap[0:size-1]
		size--

		j := 1
		v := heap[j-1]
		for done := false; !done && 2*j <= size; {
			m := 2 * j
			if m+1 <= size && heap[m] > heap[m-1] {
				m = m + 1
			}
			if heap[j-1] < heap[m-1] {
				heap[j-1] = heap[m-1]
				j = m
				heap[j-1] = v
			} else {
				done = true
			}
		}
	}
	return heap[0]
}

// for ref, build all nums as a heap
// then delete k times
func findKthLargest3(nums []int, k int) int {
	l := len(nums)
	BuildMaxHeap(nums, l)

	if k == 1 {
		return nums[0]
	}
	for i := 1; i < k; i++ {
		nums[0], nums[l-i] = nums[l-i], nums[0]
		Siftdown2(nums, 0, l-i)
	}
	return nums[0]
}

func BuildMaxHeap(s []int, size int) {
	for i := size/2 - 1; i >= 0; i-- {
		Siftdown2(s, i, size)
	}
}

func Siftdown2(s []int, i int, size int) {
	tmp := s[i]
	j := i*2 + 1
	if j+1 < size && s[j] < s[j+1] {
		j++
	}
	for j < size {
		if tmp > s[j] {
			break
		}
		s[i] = s[j]
		i = j
		j = j*2 + 1
		if j+1 < size && s[j] < s[j+1] {
			j++
		}
	}
	s[i] = tmp
}

func main() {
	s := []int{3, 2, 1, 5, 6, 4}
	s2 := []int{3, 2, 3, 1, 2, 4, 5, 5, 6, 7, 7, 8, 2, 3, 1, 1, 1, 10, 11, 5, 6, 2, 4, 7, 8, 5, 6}

	// test
	//heap := MinHeap(s2, 20)
	//fmt.Println(heap)
	//
	//maxheap := MaxHeap(s2)
	//fmt.Println(maxheap)

	//SetTop(heap, 7)
	//fmt.Println(heap)

	// seems works
	//fmt.Println(findKthLargest2(s, 2))
	//fmt.Println(findKthLargest2(s2, 20))

	// verify
	//fmt.Println(findKthLargest(s, 2))
	//fmt.Println(findKthLargest(s2, 20))
	//fmt.Println(s2)

	//fmt.Println(findKthLargest4(s, 2))
	//fmt.Println(findKthLargest4(s2, 20))

	fmt.Println(findKthLargest5(s, 2))
	fmt.Println(findKthLargest5(s2, 20))
}

//----------------------------------------------------------
// try another method based on QuickSelect
//----------------------------------------------------------
func LomutoPartition(a []int, l, r int) int {
	s := l
	for i := l + 1; i <= r; i++ {
		if a[i] > a[l] {
			s += 1
			a[s], a[i] = a[i], a[s]
		}
	}
	a[s], a[l] = a[l], a[s]
	return s
}

func quickSelect(a []int, l, r, k int) int {
	var s int
	for s = LomutoPartition(a, l, r); s != k-1; {
		if s > k-1 {
			s = LomutoPartition(a, l, s-1)
		} else {
			s = LomutoPartition(a, s+1, r)
		}
	}
	return a[s]
}

func findKthLargest5(nums []int, k int) int {
	return quickSelect(nums, 0, len(nums)-1, k)
}
