package main

import (
	"math"
	"fmt"
)

// Suppose Andy and Doris want to choose a restaurant for dinner,
// and they both have a list of favorite restaurants represented by strings.
//
// You need to help them find out their common interest with the least list index sum.
// If there is a choice tie between answers, output all of them with no order requirement.
// You could assume there always exists an answer.
//
// Example 1:
//
// Input:
// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
//
// Output: ["Shogun"]
// Explanation: The only restaurant they both like is "Shogun".
//
// Example 2:
//
// Input:
// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["KFC", "Shogun", "Burger King"]
//
// Output: ["Shogun"]
// Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).

// Note:
// The length of both lists will be in the range of [1, 1000].
// The length of strings in both lists will be in the range of [1, 30].
// The index is starting from 0 to the list length minus 1.
// No duplicates in both lists.

// hash
func findRestaurant(list1 []string, list2 []string) []string {
	var least = math.MaxInt64
	var auxiliary = make(map[string]int)
	var candidate = make(map[int][]string)

	for i, s := range list1 {
		auxiliary[s] = i
	}
	for i, s := range list2 {
		if _, ok := auxiliary[s]; ok {
			auxiliary[s] += i
			if auxiliary[s] <= least {
				least = auxiliary[s]
				candidate[least] = append(candidate[least], s)
			}
		}
	}
	return candidate[least]
}

func main() {
	list1 := []string{"Shogun", "Tapioca Express", "Burger King", "KFC"}
	list2 := []string{"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"}
	fmt.Println(findRestaurant(list1, list2))

	list1 = []string{"Shogun", "Tapioca Express", "Burger King", "KFC"}
	list2 = []string{"KFC", "Shogun", "Burger King",}
	fmt.Println(findRestaurant(list1, list2))

}
