package binaryWatch

import (
	"github.com/xxks-kkk/shuati/include/goinclude"
	"testing"
)

func TestGenerateTimeBasedOnPos(t *testing.T) {
	var tests = []struct {
		input []int
		want  string
	}{
		{[]int{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, "8:00"},
		{[]int{0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, "4:00"},
		{[]int{0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, "2:00"},
		{[]int{0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, "1:00"},
		{[]int{0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, "0:32"},
		{[]int{0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, "0:16"},
		{[]int{0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, "0:08"},
		{[]int{0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, "0:04"},
		{[]int{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, "0:02"},
		{[]int{0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, "0:01"},
		{[]int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, "0:00"},
	}
	for _, test := range tests {
		if got, _ := generateTimeBasedOnPos(test.input); got != test.want {
			t.Errorf("generateTimeBasedOnPos(%q) = %v", test.input, got)
		}
	}
}

func TestReadBinaryWatch(t *testing.T) {
	var tests = []struct {
		input int
		want  []string
	}{
		{1, []string{"1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"}},
		{0, []string{"0:00"}},
		{2, []string{"0:03", "0:05", "0:06", "0:09", "0:10", "0:12", "0:17", "0:18", "0:20", "0:24", "0:33", "0:34", "0:36", "0:40", "0:48", "1:01", "1:02", "1:04", "1:08", "1:16", "1:32", "2:01", "2:02", "2:04", "2:08", "2:16", "2:32", "3:00", "4:01", "4:02", "4:04", "4:08", "4:16", "4:32", "5:00", "6:00", "8:01", "8:02", "8:04", "8:08", "8:16", "8:32", "9:00", "10:00"}},
	}
	for _, test := range tests {
		if got := readBinaryWatch(test.input); !goinclude.StringSliceCompare(got, test.want) {
			t.Errorf("readBinaryWatch(%q) = %v, expect: %v", test.input, got, test.want)
		}
	}
}
