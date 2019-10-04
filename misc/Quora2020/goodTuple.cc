#include <vector>
#include "cpputility.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
  int goodTuples(vector<int>& array) {
    if (array.size() < 3) return 0;
    int output = 0;
    unordered_map<int, int> m;
    for(int i = 0; i < array.size()-2; ++i) {
      for(int j = i; j < i+3; ++j) {
        m[array[j]]++;
      }
      if (m.size() == 2) {
        output++;
      }
      m.clear();
    }
    return output;
  }
};


class Test {
public:
  void test_goodTuples() {
    Solution sol;
    struct testCase {
      vector<int> array;
      int expected;
    };
    vector<testCase> test_cases = {
      {{1,1,2,1,5,3,2,3}, 3},
      {{1,1}, 0},
      {{1,1,1}, 0},
      {{1,1,2}, 1},
    };
    for(auto&& test_case: test_cases) {
      int got = sol.goodTuples(test_case.array);
      if (got != test_case.expected) {
        printf("goodTuples(%s) = %d\n",
               CPPUtility::oneDVectorStr<int>(test_case.array).c_str(),
               got);
        assert(false);
      }
    }
  }
};

int main() {
  Test test;
  test.test_goodTuples();
}
