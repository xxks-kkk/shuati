package binaryWatch

import (
	"testing"
)

func TestGenerateTimeBasedOnPos(t *testing.T) {
	var tests = []struct {
		input [10]int
		want  string
	}{
		{[10]int{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, "8:00"},
		{[10]int{0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, "4:00"},
		{[10]int{0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, "2:00"},
		{[10]int{0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, "1:00"},
		{[10]int{0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, "0:32"},
		{[10]int{0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, "0:16"},
		{[10]int{0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, "0:08"},
		{[10]int{1, 0, 0, 0, 0, 0, 0, 1, 0, 0}, "0:04"},
		{[10]int{1, 0, 0, 0, 0, 0, 0, 0, 1, 0}, "0:02"},
		{[10]int{1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, "0:01"},
	}
	for _, test := range tests {
		if got := generateTimeBasedOnPos(test.input); got != test.want {
			t.Errorf("generateTimeBasedOnPos(%q) = %v", test.input, got)
		}
	}
}
