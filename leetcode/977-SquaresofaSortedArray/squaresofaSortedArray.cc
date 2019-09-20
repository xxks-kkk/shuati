#include<vector>
#include<assert.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(auto&& i: A)
        {
            if (i < 0)
                i *= -1;
        }
        sort(A.begin(), A.end(), less<int>());
        vector<int> res;
        for(auto&& i: A)
        {
            res.push_back(i*i);
        }
        return res;
    }
};

using ptr2sortedSquares = vector<int> (Solution::*)(vector<int>&);

void test(ptr2sortedSquares pfcn)
{
    Solution sol;
    struct testCase {
      vector<int> input;
      vector<int> expected;
    };
    vector<testCase> test_cases = {
      {{-4,-1,0,3,10}, {0,1,9,16,100}},
      {{-7,-3,2,3,11}, {4,9,9,49,121}},
    };
    for (auto && test_case: test_cases) {
      assert((sol.*pfcn)(test_case.input) == test_case.expected);
    }
}

int main()
{
  ptr2sortedSquares pfcn = &Solution::sortedSquares;
  test(pfcn);
}
