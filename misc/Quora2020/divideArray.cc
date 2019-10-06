#include <vector>
#include "cpputility.h"
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> divideArray(vector<int>& array) {
    vector<vector<int>> res;
    res.push_back({});
    res.push_back({});
    unordered_map<int, int> m;
    for(auto&& item: array) {
      m[item]++;
      if (m[item] > 2) return {};
    }
    for(auto&& item: m) {
      if (item.second == 2) {
        res[0].push_back(item.first);
        res[1].push_back(item.first);
      } else {
        if (res[0].size() > res[1].size()) {
          res[1].push_back(item.first);
        } else {
          res[0].push_back(item.first);
        }
      }
    }
    return res;
  }
};


class Test {
public:
  void test_divideArray() {
    Solution sol;
    struct testCase {
      vector<int> array;
      vector<vector<int>> expected;
    };
    vector<testCase> test_cases = {
      {{1,1,2,2,3,3}, {{1,2,3},{1,2,3}}},
      {{1,1,2,2,3,4}, {{1,2,3},{1,2,4}}},
      {{1,1,1}, {}},
    };
    for(auto&& test_case: test_cases) {
      auto got = sol.divideArray(test_case.array);
      if (!CPPUtility::check_twoDVector_equal<int>(got, test_case.expected)) {
        printf("divideArray(%s) = %s\n",
               CPPUtility::oneDVectorStr<int>(test_case.array).c_str(),
               CPPUtility::twoDVectorStr<int>(got).c_str());
        assert(false);
      }
    }
  }
};

int main() {
  Test test;
  test.test_divideArray();
}
