package main

import (
	"testing"
	"math/rand"
	"time"
)

func TestGetSum(t *testing.T) {
	rng := rand.New(rand.NewSource(time.Now().UTC().Unix()))

	for i := 0; i < 100; i++ {
		a, b := rng.Int(), rng.Int()
		if getSum2(a, b) != a+b {
			t.Errorf("%d + %d = %d, want %d\n", a, b, getSum2(a, b), a+b)
		}
	}
}

func BenchmarkGetSum(b *testing.B) {
	rng := rand.New(rand.NewSource(time.Now().UTC().Unix()))
	m, n := rng.Int(), rng.Int()
	for i := 0; i < b.N; i++ {
		getSum(m, n)
	}
}

func BenchmarkGetSum2(b *testing.B) {
	rng := rand.New(rand.NewSource(time.Now().UTC().Unix()))
	m, n := rng.Int(), rng.Int()
	for i := 0; i < b.N; i++ {
		getSum2(m, n)
	}
}
