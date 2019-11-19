#include "cpputility.h"
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    // invariant: target \in [left, right]
    int left = 0, right = nums.size()-1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) return mid;
      else if (nums[mid] < nums[right]) {
        if (nums[mid] < target && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else if (nums[mid] >= nums[right]) {
        if (nums[left] <= target && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
    }
    return -1;
  }
};

using ptr2search = int (Solution::*)(vector<int>&, int);

void test(ptr2search pfcn) {
  Solution sol;
  struct testCase {
    vector<int> nums;
    int target;
    int expected;
  };
  vector<testCase> test_cases = {
    {{4,5,6,7,0,1,2},0,4},
    {{4,5,6,7,0,1,2},3,-1},
    {{},5,-1},
    {{5,1,2,3,4},1,1},
    {{3,5,1},3,0},
  };
  for(auto&& test_case: test_cases) {
    auto got = (sol.*pfcn)(test_case.nums, test_case.target);
    if (got != test_case.expected) {
      printf("%s(%s, %d) = %d\n",
             "search",
             CPPUtility::oneDVectorStr<int>(test_case.nums).c_str(),
             test_case.target,
             got);
      assert(false);
    }
  }
}

int main() {
  ptr2search pfcn = &Solution::search;
  test(pfcn);
}
