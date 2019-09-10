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
