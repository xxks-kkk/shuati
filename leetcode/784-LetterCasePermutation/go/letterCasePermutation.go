package leetcode

import (
	"errors"
	"fmt"
	"strings"
	"unicode"
	"unicode/utf8"
)

// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.
// Examples:
// Input: S = "a1b2"
// Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
// Input: S = "3z4"
// Output: ["3z4", "3Z4"]
// Input: S = "12345"
// Output: ["12345"]
// Note:
// - S will be a string with length between 1 and 12.
// - S will consist only of letters or digits.

type Action int

const (
	LOWER Action = iota
	UPPER
)

// Backtracking
func LetterCasePermutation(S string) []string {
	var res []string
	var pos []int
	// filter out positions of the string that are runes
	for i, r := range S {
		if unicode.IsLetter(r) {
			pos = append(pos, i)
		}
	}
	return backtrack([]rune(S), res, pos, []Action{})
}

func backtrack(S []rune, res []string, pos []int, actionList []Action) []string {
	// if the length of actionList equals to the number of runes that needed to apply
	// we apply the actions in batch based on actionList
	if len(actionList) == len(pos) {
		var tmp []rune = S
		for i, action := range actionList {
			val, _ := applyAction(string(tmp[pos[i]]), action)
			decodedRune, _ := utf8.DecodeRuneInString(val)
			tmp[pos[i]] = decodedRune
		}
		res = append(res, string(tmp))
	} else {
		for _, action := range [...]Action{LOWER, UPPER} {
			actionList = append(actionList, action)
			res = backtrack(S, res, pos, actionList)
			actionList = actionList[:len(actionList)-1]
		}
	}
	return res
}

// applyAction applies given action to the c and returns
// the result after the action applied
func applyAction(c string, action Action) (string, error) {
	switch action {
	case LOWER:
		return strings.ToLower(c), nil
	case UPPER:
		return strings.ToUpper(c), nil
	default:
		return "", errors.New(fmt.Sprintf("Invalid action: %v", action))
	}
}
