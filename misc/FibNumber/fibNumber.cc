#include<assert.h>
#include<vector>

using namespace std;

class Solution {
public:
  // fibNumber calculates nth (0-indexed) fibonacci number:
  // 1 (idx: 0), 1 (idx: 1), 2 (idx: 2), ...
  int fibNumber(int n)
  {
    // We use Dynamic Programming approach for the calculation
    int res = 0;
    int last = 1;
    int nextLast = 1;
    if (n < 2)
    {
      return 1;
    }
    for (int i = 2; i <= n; ++i)
    {
      res = last + nextLast; // F(n) = F(n-1) + F(n-2)
      nextLast = last;
      last = res;
    }
    return res;
  }
};

using ptr2fibNumber = int (Solution::*)(int);

void test(ptr2fibNumber pfcn)
{
  Solution sol;
  struct testCase {
    int input;
    int expected;
  };
  vector<testCase> test_cases = {
    { 0, 1 },
    { 1, 1 },
    { 7, 21},
    {11, 144}
  };
  for(auto && test_case: test_cases)
  {
    assert((sol.*pfcn)(test_case.input) == test_case.expected);
  }
}

int main()
{
  ptr2fibNumber pfcn = &Solution::fibNumber;
  test(pfcn);
}
