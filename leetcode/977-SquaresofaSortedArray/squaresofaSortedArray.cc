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

  // Two pointers approach
  vector<int> sortedSquares2(vector<int>& A) {
    int ptr1 = 0;  // ptr1 points to the start of the negative number subsequence in A
    int ptr2 = 0;  // ptr2 points to the start of the positive number subsequence in A
    vector<int> res;
    for(auto&& i: A)
    {
      if (i < 0)
      {
        ptr2++;
      }
      else {
          break;
      }
    }
    int ptr1_end = -1;
    ptr1 = ptr2 - 1;
    while (ptr1 != ptr1_end && ptr2 != A.size())
    {
      int cand1 = A[ptr1]*A[ptr1];
      int cand2 = A[ptr2]*A[ptr2];
      if (cand1 > cand2)
      {
        res.push_back(cand2);
        ptr2++;
      }
      else
      {
        res.push_back(cand1);
        ptr1--;
      }
    }
    while(ptr1 != ptr1_end)
    {
      res.push_back(A[ptr1]*A[ptr1]);
      ptr1--;
    }
    while(ptr2 != A.size())
    {
      res.push_back(A[ptr2]*A[ptr2]);
      ptr2++;
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
  pfcn = &Solution::sortedSquares2;
  test(pfcn);
}
