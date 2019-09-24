#include <vector>
#include <string>
#include <assert.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
  int distinctTriplets(vector<int> nums) {
    int count = 0;
    for(int i = 0; i < nums.size() - 2; ++i) {
      if (nums[i] != nums[i+1] && nums[i+1] != nums[i+2]) {
        count++;
      }
    }
    return count;
  }
};

class Test {
public:
  void test_distinctTriplets() {
    Solution sol;
    struct testCase {
      vector<int> nums;
      int expected;
    };
    vector<testCase> test_cases = {
      {{1,3,2,4,4,5,6,7,8}, 5},
    };
    for(auto && test_case: test_cases) {
      int got = sol.distinctTriplets(test_case.nums);
      if (got != test_case.expected) {
        string cand = "[";
        for(auto&& item: test_case.nums) {
          cand += to_string(item);
        }
        cand += "]";
        printf("distinctTriplets(%s) = %s\n", cand.c_str(), to_string(got).c_str());
      }
    }
  }
};

int main() {
  Test test;
  test.test_distinctTriplets();
}
