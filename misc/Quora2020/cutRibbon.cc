#include <vector>
#include "cpputility.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
  int cutRibbon(vector<int>& array, int target) {
    int max_size = 0;
    int max_val = *max_element(array.begin(), array.end());
    vector<int> cutCands(max_val);
    for(int i = 0; i < max_val; ++i) {
      cutCands[i] = i+1;
    }
    int left = 0, right = cutCands.size()-1;    
    while (left <= right) {
      int mid = (right + left) / 2;
      int num_cuts = numCuts(array, cutCands[mid]);
      if (num_cuts == target) {
          if (cutCands[mid] > max_size) max_size = cutCands[mid];
          left = mid+1;
      } else if (num_cuts < target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return max_size;
  }
private:
  int numCuts(vector<int>& array, int cutSize) {
    int count = 0;
    for(auto&& item: array) {
      count += (item / cutSize);
    }
    return count;
  }
};


class Test {
public:
  void test_cutRibbon() {
    Solution sol;
    struct testCase {
      vector<int> array;
      int k;
      int expected;
    };
    vector<testCase> test_cases = {
      {{1,2,3,4,9}, 5, 3},
      {{3,5,7,9}, 10, 2},
      {{6,7,9,9}, 4, 6},
    };
    for(auto&& test_case: test_cases) {
      int got = sol.cutRibbon(test_case.array, test_case.k);
      if (got != test_case.expected) {
        printf("cutRibbon(%s, %d) = %d\n",
               CPPUtility::oneDVectorStr<int>(test_case.array).c_str(),
               test_case.k,
               got);
        assert(false);
      }
    }
  }
};

int main() {
  Test test;
  test.test_cutRibbon();
}
