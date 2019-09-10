package permutations

import (
	"errors"
	"fmt"
	"github.com/xxks-kkk/shuati/leetcode/goinclude"
	"sync"
	"testing"
)

func TestPermute(t *testing.T) {
	var tests = []struct {
		nums []int
		want [][]int
	}{
		{[]int{1, 2, 3}, [][]int{{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}}},
		{[]int{5, 4, 6, 2}, [][]int{{5, 4, 6, 2}, {5, 4, 2, 6}, {5, 6, 4, 2}, {5, 6, 2, 4}, {5, 2, 4, 6}, {5, 2, 6, 4}, {4, 5, 6, 2}, {4, 5, 2, 6}, {4, 6, 5, 2}, {4, 6, 2, 5}, {4, 2, 5, 6}, {4, 2, 6, 5}, {6, 5, 4, 2}, {6, 5, 2, 4}, {6, 4, 5, 2}, {6, 4, 2, 5}, {6, 2, 5, 4}, {6, 2, 4, 5}, {2, 5, 4, 6}, {2, 5, 6, 4}, {2, 4, 5, 6}, {2, 4, 6, 5}, {2, 6, 5, 4}, {2, 6, 4, 5}}},
	}
	for _, test := range tests {
		if got := permute(test.nums); !goinclude.IntNestedSliceCompare(got, test.want) {
			t.Errorf("permute(%q) = %v", test.nums, got)
		}
	}
}

func TestPermuteInParallel(t *testing.T) {
	var wg sync.WaitGroup
	type test struct {
		nums []int
		want [][]int
	}
	tests := []test{
		{[]int{1, 2, 3}, [][]int{{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}}},
		{[]int{5, 4, 6, 2}, [][]int{{5, 4, 6, 2}, {5, 4, 2, 6}, {5, 6, 4, 2}, {5, 6, 2, 4}, {5, 2, 4, 6}, {5, 2, 6, 4}, {4, 5, 6, 2}, {4, 5, 2, 6}, {4, 6, 5, 2}, {4, 6, 2, 5}, {4, 2, 5, 6}, {4, 2, 6, 5}, {6, 5, 4, 2}, {6, 5, 2, 4}, {6, 4, 5, 2}, {6, 4, 2, 5}, {6, 2, 5, 4}, {6, 2, 4, 5}, {2, 5, 4, 6}, {2, 5, 6, 4}, {2, 4, 5, 6}, {2, 4, 6, 5}, {2, 6, 5, 4}, {2, 6, 4, 5}}},
	}
	done := make(chan error)
	for _, testCase := range tests {
		wg.Add(1)
		go func(testCase test) {
			defer wg.Done()
			got := permute(testCase.nums)
			if !goinclude.IntNestedSliceCompare(got, testCase.want) {
				done <- errors.New(fmt.Sprintf("permute(%q) = %v", testCase.nums, got))
			}
		}(testCase)
	}
	go func() {
		wg.Wait()
		close(done)
	}()
	for err := range done {
		t.Error(err)
	}
}
