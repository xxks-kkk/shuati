use std::collections::HashMap;

#[allow(dead_code)]
struct Solution {}

impl Solution {
    #[allow(dead_code)]
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut dict: HashMap<i32, i32> = HashMap::new();
        for idx in 0..nums.len() {
            if dict.contains_key(&(target - nums[idx])) {
                return vec![dict[&(target - nums[idx])], idx as i32];
            } else {
                dict.insert(nums[idx], idx as i32);
            }
        }
        panic!("No solution to TwoSum");
    }
}

#[test]
fn test_1() {
    let nums = vec![2, 7, 11, 15];
    let target = 9;
    assert_eq!(Solution::two_sum(nums, target), vec![0, 1]);
}
