package main

import "fmt"

// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
// In other words, one of the first string's permutations is the substring of the second string.
//
// Example 1:
// Input:s1 = "ab" s2 = "eidbaooo"
//
// Output:True
// Explanation: s2 contains one permutation of s1 ("ba").
//
// Example 2:
// Input:s1 = "ab" s2 = "eidboaoo"
// Output: False
//
// Note:
// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10, 000].

// naive implementation: time limit exceed...
func checkInclusion(s1 string, s2 string) bool {
	match := make(map[rune]int)
	left := make(map[rune]int)
	var matchCnt, leftCnt int
	for _, r := range s1 {
		left[r]++
		leftCnt++
	}
	chars := []rune(s2)
	for i := 0; i < len(chars); i++ {
		r := chars[i]
		if _, ok := left[r]; ok {
			matchCnt++
			match[r]++
			if leftCnt--; leftCnt == 0 {
				return true
			}
			if left[r]--; left[r] == 0 {
				delete(left, r)
			}
		} else {
			if matchCnt != 0 {
				i -= matchCnt
				leftCnt += matchCnt
				matchCnt = 0
				for k := range match {
					left[k] += match[k]
					delete(match, k)
				}
			}
		}
	}
	return false
}

// ref: https://leetcode.com/problems/permutation-in-string/discuss/
// clever ! l will never large than r
/*
public boolean checkInclusion(String s1, String s2) {
	int[] count = new int[128];
	for(int i = 0; i < s1.length(); i++) count[s1.charAt(i)]--;
	for(int l = 0, r = 0; r < s2.length(); r++) {
		if (++count[s2.charAt(r)] > 0)
			while(--count[s2.charAt(l++)] != 0) { }
		else if ((r - l + 1) == s1.length()) return true;
	}
	return s1.length() == 0;
}
*/

// very fast !
func checkInclusion2(s1 string, s2 string) bool {
	var count = [128]int{}
	for _, r := range s1 {
		count[r]--
	}
	for l, r := 0, 0; r < len(s2); r++ {
		if count[s2[r]]++; count[s2[r]] > 0 {
			for count[s2[l]]--; count[s2[l]] != 0; {
				l++
				count[s2[l]]--
			}
			// start the next one
			l++
		} else {
			if r-l+1 == len(s1) {
				return true
			}
		}
	}
	return len(s1) == 0
}

func main() {
	fmt.Println(checkInclusion("ab", "eidbaooo"))
	fmt.Println(checkInclusion2("ab", "eidbaooo"))

	fmt.Println()
	fmt.Println(checkInclusion("ab", "eidboaoo"))
	fmt.Println(checkInclusion2("ab", "eidboaoo"))

	fmt.Println()
	fmt.Println(checkInclusion("ooeab", "eidboaoo"))
	fmt.Println(checkInclusion2("ooeab", "eidboaoo"))

	fmt.Println()
	fmt.Println(checkInclusion("i", "eidboaoo"))
	fmt.Println(checkInclusion2("i", "eidboaoo"))

	// holy shit
	fmt.Println()
	fmt.Println(checkInclusion("adc", "dcda"))
	fmt.Println(checkInclusion2("adc", "dcda"))

	fmt.Println()
	fmt.Println(checkInclusion("rokx", "otrxvfszxroxrzdsltg"))
	fmt.Println(checkInclusion2("rokx", "otrxvfszxroxrzdsltg"))

	fmt.Println()
	s1 := "trinitrophenylmethylnitramine"
	s2 := "dinitrophenylhydrazinetrinitrophenylmethylnitramine"
	fmt.Println(checkInclusion(s1, s2))
	fmt.Println(checkInclusion2(s1, s2))
}
