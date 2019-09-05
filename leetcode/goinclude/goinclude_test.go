package goinclude

import (
	"testing"
)

func TestStringSliceCompare(t *testing.T) {
	var tests = []struct {
		s1   []string
		s2   []string
		want bool
	}{
		{[]string{"a1b2", "a1B2", "A1b2", "A1B2"}, []string{"a1b2", "a1B2", "A1b2", "A1B2"}, true},
		{[]string{"3z4"}, []string{"3z4", "3Z4"}, false},
		{[]string{"3Z4", "3z4"}, []string{"3z4", "3Z4"}, true},
	}
	for _, test := range tests {
		if got := StringSliceCompare(test.s1, test.s2); got != test.want {
			t.Errorf("StringSliceCompare(%q, %q) = %v", test.s1, test.s2, got)
		}
	}
}
