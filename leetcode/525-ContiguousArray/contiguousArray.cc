#include <vector>
#include <unordered_map>
#include "cpputility.h"

using std::vector;
using std::unordered_map;
using std::max;

class Solution
{
public:
    int
    findMaxLength(vector<int> &nums)
    {
      unordered_map<int /* sum of numbers in nums */, int /* idx that reaches the sum for the first time */> m;
      int sum = 0;
      int maxLength = 0;
      m[0] = -1;
      for (int i = 0; i < nums.size(); ++i)
      {
        sum += nums[i] == 1 ? 1 : -1;
        if (m.find(sum) != m.end())
        {
          maxLength = max(maxLength, i - (m[sum] + 1) + 1);
        }
        else
        {
          m[sum] = i;
        }
      }
      return maxLength;
    }
};

using ptr2findMaxLength = int (Solution::*)(vector<int> &);

struct testFuncsInfo
{
    ptr2findMaxLength pfcn;
    const char *pfcn_name;
};

void
test(ptr2findMaxLength pfcn, const char *pfcn_name)
{
  Solution sol;
  struct testCase
  {
      vector<int> nums;
      int expected;
  };
  vector<testCase> test_cases = {
      {{0, 1}, 2},
      {{0, 1, 0}, 2},
      {{0, 0, 1, 1, 1, 0, 0}, 6},
      {{0, 0, 1, 1, 0, 1, 0}, 6}
  };
  for (auto &&test_case: test_cases)
  {
    auto got = (sol.*pfcn)(test_case.nums);
    if (got != test_case.expected)
    {
      printf("%s(%s) = %s\n",
             pfcn_name,
             CPPUtility::oneDVectorStr(test_case.nums).c_str(),
             got == true ? "true" : "false");
      assert(false);
    }
  }
}

int
main()
{
  vector<testFuncsInfo> func_array = {
      FUNC_DEF(&Solution::findMaxLength)
  };
  for (auto &&func: func_array)
  {
    test(func.pfcn, func.pfcn_name);
  }
}
