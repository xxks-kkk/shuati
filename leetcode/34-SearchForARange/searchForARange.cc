#include "cpputility.h"
#include <vector>

using std::vector;

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    vector<int> res = {-1, -1};
    int left_idx = searchBoundOfTarget(nums, target, true);
    if (left_idx >= 0)
    {
      int right_idx = searchBoundOfTarget(nums, target, false);
      res[0] = left_idx;
      res[1] = right_idx;
    }
    return res;
  }

private:
  int searchBoundOfTarget(const vector<int> &nums, int target, bool isLeftBound)
  {
    // invariant: the bound of target (left/right) \in [left, right]
    int left = 0, right = nums.size() - 1, res = -1;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target)
      {
        res = mid;
        if (isLeftBound)
          right = mid - 1;
        else
          left = mid + 1;
      }
      else if (nums[mid] > target)
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }
    return res;
  }
};

using ptr2searchRange = vector<int> (Solution::*)(vector<int> &, int);

void test(ptr2searchRange pfcn)
{
  Solution sol;
  struct testCase
  {
    vector<int> nums;
    int target;
    vector<int> expected;
  };
  vector<testCase> test_cases = {
      {{5, 7, 7, 8, 8, 10}, 8, {3, 4}},
      {{5, 7, 7, 8, 8, 10}, 6, {-1, -1}}};
  for (auto &&test_case : test_cases)
  {
    auto got = (sol.*pfcn)(test_case.nums, test_case.target);
    if (got != test_case.expected)
    {
      printf("%s(%s,%d) = %s\n",
             "searchRange",
             CPPUtility::oneDVectorStr(test_case.nums).c_str(),
             test_case.target,
             CPPUtility::oneDVectorStr(got).c_str());
      assert(false);
    }
  }
}

int main()
{
  ptr2searchRange pfcn = &Solution::searchRange;
  test(pfcn);
}
