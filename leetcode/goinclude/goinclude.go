// goinclude contains utility function used throughout repo
package goinclude

import (
	"reflect"
)

// TODO: can make this more generic to compare two slice of elements with any type
// and see if they are equal
// StringSliceCompare compares string slice s1 with
// string slice s2 to see if they have the same set of elements
func StringSliceCompare(s1 []string, s2 []string) bool {
	seen_s1 := make(map[string]bool)
	for _, str := range s1 {
		if !seen_s1[str] {
			seen_s1[str] = true
		}
	}
	seen_s2 := make(map[string]bool)
	for _, str := range s2 {
		if !seen_s2[str] {
			seen_s2[str] = true
		}
	}
	return reflect.DeepEqual(seen_s1, seen_s2)
}
