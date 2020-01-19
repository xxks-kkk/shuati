#include<vector>
#include "cpputility.h"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
      // keep the following invariant during the partitioning:
      // bottom: [0, smaller)
      // equal: [smaller, equal)
      // unclassified: [equal, larger)
      // top: [larger, nums.size())
      int smaller = 0, equal = 0, larger = nums.size();
      int pivot = 1;
      while (equal < larger) {
        if (nums[equal] < pivot) {
          swap(nums[smaller++], nums[equal++]);
        } else if (nums[equal] == pivot) {
          equal++;
        } else {
          swap(nums[equal], nums[--larger]);
        }
      }
    }
};

using ptr2sortColors = void (Solution::*)(vector<int>&);

void test(ptr2sortColors pfcn) {
  Solution sol;
  struct testCase {
    vector<int> nums;
    vector<int> expected;
  };
  vector<testCase> test_cases = {
    {{2,0,2,1,1,0}, {0,0,1,1,2,2}}
  };
  for(auto&& test_case: test_cases) {
    vector<int> nums_copy(test_case.nums);
    (sol.*pfcn)(test_case.nums);
    if (test_case.nums != test_case.expected) {
      printf("%s(%s) -> %s\n",
             "sortColors",
             CPPUtility::oneDVectorStr<int>(nums_copy).c_str(),
             CPPUtility::oneDVectorStr<int>(test_case.nums).c_str());
      assert(false);
    }
  }  
}

int main() {
  ptr2sortColors pfcn = &Solution::sortColors;
  test(pfcn);
}
