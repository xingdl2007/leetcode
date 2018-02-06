package main

import (
	"sort"
	"fmt"
	"math"
)

// Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0]
// is a name, and the rest of the elements are emails representing emails of the account.
//
// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some
// email that is common to both accounts. Note that even if two accounts have the same name, they may belong to
// different people as people could have the same name. A person can have any number of accounts initially,
// but all of their accounts definitely have the same name.
//
// After merging the accounts, return the accounts in the following format: the first element of each account is
// the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
//
// Example 1:
//
// Input:
// accounts = [["John", "johnsmith@mail.com", "john00@mail.com"],
// ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
//
// Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],
// ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
//
// Explanation:
// The first and third John's are the same person as they have the common email "johnsmith@mail.com".
// The second John and Mary are different people as none of their email addresses are used by other accounts.

// We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
// ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
//
// Note:
//
// The length of accounts will be in the range [1, 1000].
// The length of accounts[i] will be in the range [1, 10].
// The length of accounts[i][j] will be in the range [1, 30].

// See uf/accounts for a better solution, with union-find, elegant and fast!!
func accountsMerge(accounts [][]string) [][]string {
	merged := make(map[string][][]string)
	for _, s := range accounts {
		sort.Strings(s[1:])
		s = duplicate(s)
		merged[s[0]] = append(merged[s[0]], s)
	}
	var ret [][]string
	for _, v := range merged {
		v = merge(v)
		for _, n := range v {
			sort.Strings(n[1:])
			ret = append(ret, n)
		}
	}
	return ret
}

func duplicate(str []string) []string {
	i := 0
	last := ""
	for j := 0; j < len(str); j++ {
		if str[j] != last {
			str[i] = str[j]
			last = str[i]
			i++
		}
	}
	return str[:i]
}

// positive
func duplicate2(array []int) []int {
	i := 0
	last := -1
	for j := 0; j < len(array); j++ {
		if array[j] != last {
			array[i] = array[j]
			last = array[i]
			i++
		}
	}
	return array[:i]
}

func smallest(array ...int) int {
	r := math.MaxInt64
	for _, a := range array {
		if a < r {
			r = a
		}
	}
	return r
}

// union find: find all connected component
func merge(data [][]string) [][]string {
	if len(data) <= 1 {
		return data
	}
	// start from 0
	registry := make(map[string]int)
	var union = func(s, t int) {
		if s == t {
			return
		}
		for mail, id := range registry {
			if id == s {
				registry[mail] = t
			}
		}
		fmt.Println(registry)
	}
	username := data[0][0]
	ccid := 0
	cnt := ccid
	for _, row := range data {
		var valid []int
		var newcc = true
		for _, mail := range row[1:] {
			if id, ok := registry[mail]; ok {
				valid = append(valid, id)
				newcc = false
			}
		}
		if newcc {
			for _, mail := range row[1:] {
				registry[mail] = ccid
			}
			ccid++
			cnt++
		} else {
			// must exist
			p := smallest(valid...)
			for _, mail := range row[1:] {
				registry[mail] = p
			}
			if len(valid) > 1 {
				// duplicate is harmful
				sort.Ints(valid)
				valid = duplicate2(valid)
				for _, v := range valid[1:] {
					union(v, p)
					cnt--
				}
			}
		}
	}
	res := make([][]string, cnt)
	for i := 0; i < cnt; i++ {
		res[i] = append(res[i], username)
	}
	mapping := make(map[int]int)
	start := 0
	for k, v := range registry {
		if _, ok := mapping[v]; !ok {
			mapping[v] = start
			start++
		}
		res[mapping[v]] = append(res[mapping[v]], k)
	}
	return res
}

func main() {
	accounts := [][]string{{"John", "johnsmith@mail.com", "john00@mail.com"},
		{"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}}
	fmt.Println(accountsMerge(accounts))

	//fmt.Println(duplicate([]string{"a", "a", "a"}))
	accounts = [][]string{
		{"David", "David0@m.co", "David1@m.co"},
		{"David", "David3@m.co", "David4@m.co"},
		{"David", "David4@m.co", "David5@m.co"},
		{"David", "David2@m.co", "David3@m.co"},
		{"David", "David1@m.co", "David2@m.co"},
	}
	fmt.Println(accountsMerge(accounts))

	accounts = [][]string{
		{"Lily", "Lily3@m.co", "Lily4@m.co", "Lily17@m.co"},
		{"Lily", "Lily5@m.co", "Lily3@m.co", "Lily23@m.co"},
		{"Lily", "Lily0@m.co", "Lily1@m.co", "Lily8@m.co"},
		{"Lily", "Lily14@m.co", "Lily23@m.co"},
		{"Lily", "Lily4@m.co", "Lily5@m.co", "Lily20@m.co"},
		{"Lily", "Lily1@m.co", "Lily2@m.co", "Lily11@m.co"},
		{"Lily", "Lily2@m.co", "Lily0@m.co", "Lily14@m.co"},
	}
	fmt.Println(accountsMerge(accounts))

	accounts = [][]string{
		{"Hanzo", "Hanzo2@m.co", "Hanzo3@m.co"},
		{"Hanzo", "Hanzo4@m.co", "Hanzo5@m.co"},
		{"Hanzo", "Hanzo0@m.co", "Hanzo1@m.co"},
		{"Hanzo", "Hanzo3@m.co", "Hanzo4@m.co"},
		{"Hanzo", "Hanzo7@m.co", "Hanzo8@m.co"},
		{"Hanzo", "Hanzo1@m.co", "Hanzo2@m.co"},
		{"Hanzo", "Hanzo6@m.co", "Hanzo7@m.co"},
		{"Hanzo", "Hanzo5@m.co", "Hanzo6@m.co"},
	}
	fmt.Println(accountsMerge(accounts))
}
