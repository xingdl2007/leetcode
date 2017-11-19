package accounts

import "sort"

// Keep track of sets under union operations.
// Initially, everything is in its own set.
// not concurrency safe
type UnionFind struct {
	edges []int
	in    map[string]int
	sz    int
}

func (this *UnionFind) Init() {
	this.in = make(map[string]int)
}

func (this *UnionFind) FindOrInsert(s string) int {
	if _, found := this.in[s]; !found {
		this.edges = append(this.edges, this.sz)
		this.in[s] = this.sz
		this.sz++
	}
	return this.in[s]
}

// join the sets containing A and B
func (this *UnionFind) Union(e0, e1 string) {
	i := this.FindOrInsert(e0)
	j := this.FindOrInsert(e1)
	as := this.Get(i)
	bs := this.Get(j)
	this.edges[int(as)] = bs
}

// return a representative for the set
func (this *UnionFind) Get(i int) int {
	ip := this.edges[i]
	if ip == i {
		return i
	}
	ir := this.Get(ip)
	this.edges[i] = ir
	return ir
}

func accountsMerge(accounts [][]string) [][]string {
	ansIM := make(map[int]int)
	inAns := make(map[string]bool)
	var ans [][]string

	uf := &UnionFind{}
	uf.Init()

	for _, acnt := range accounts {
		for k := 1; k < len(acnt)-1; k++ {
			uf.Union(acnt[k], acnt[k+1])
		}
	}

	for _, acnt := range accounts {
		if len(acnt) > 1 {
			ufIdx := uf.Get(uf.FindOrInsert(acnt[1]))

			if _, found := ansIM[ufIdx]; !found {
				ansIM[ufIdx] = len(ans)
				ans = append(ans, []string{acnt[0]})
			}
			ansIdx := ansIM[ufIdx]
			for k := 1; k < len(acnt); k++ {
				if _, found := inAns[acnt[k]]; !found {
					ans[ansIdx] = append(ans[ansIdx], acnt[k])
					inAns[acnt[k]] = true
				}
			}
		}
	}

	for _, row := range ans {
		sort.Strings(row[1:])
	}
	return ans
}
