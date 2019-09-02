package leetcode

import (
	"reflect"
	"testing"
)

func TestLetterCasePermutation(t *testing.T) {
	var tests = []struct {
		input string
		want  []string
	}{
		{"a1b2", []string{"a1b2", "a1B2", "A1b2", "A1B2"}},
		{"3z4", []string{"3z4", "3Z4"}},
		{"12345", []string{"12345"}},
	}
	for _, test := range tests {
		if got := LetterCasePermutation(test.input); !reflect.DeepEqual(got, test.want) {
			t.Errorf("LetterCasePermutation(%q) = %v", test.input, got)
		}
	}
}
