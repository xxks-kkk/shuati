package permutations

// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

func permute(nums []int) [][]int {
	var tmp []int
	var res [][]int
	invalid_pos := make([]bool, len(nums))
	res = backtrack(nums, tmp, invalid_pos, res)
	return res
}

// backtrack generates all the permutations of the given `nums` and put them into `res`.
// `invalid_pos` keeps track of which number is valid to pick from `nums` to form a permutation
// `tmp`
func backtrack(nums []int, tmp []int, invalid_pos []bool, res [][]int) [][]int {
	if len(tmp) == len(nums) {
		// NOTE: make a copy to make leetcode OJ pass; not sure why I need to make a copy
		// here. From Leetcode result, I'm suspecting a "Capturing Iteration Variable"
		// (https://stackoverflow.com/questions/52980172/cannot-understand-5-6-1-caveat-capturing-iteration-variables)
		// situation can happen. However, I cannot test it out given my current test implementation.
		// Same implementation strategy (e.g., append(res, tmp)) is used in LC-401. However, OJ pass in that problem.
		// I think it might be an error for OJ?
		tmp2 := make([]int, len(tmp))
		copy(tmp2, tmp)
		res = append(res, tmp2)
	} else {
		for i, num := range nums {
			if invalid_pos[i] {
				continue
			}
			invalid_pos[i] = true
			tmp = append(tmp, num)
			res = backtrack(nums, tmp, invalid_pos, res)
			invalid_pos[i] = false
			tmp = tmp[:len(tmp)-1]
		}
	}
	return res
}
