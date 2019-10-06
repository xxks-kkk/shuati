#include <vector>
#include "cpputility.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> coolFeature(vector<int>& a, vector<int>& b, vector<vector<int>>& query) {
    vector<int> res;
    unordered_map<int, int> m;
    for(auto&& item: b) {
      m[item]++;
    }
    for(auto&& q: query) {
      if (q[0] == 0) {
        m[b[q[1]]]--;
        b[q[1]] = q[2];
        m[q[2]]++;
      } else {
        int count = 0;
        for(auto&& item: a) {
          if (m.find(q[1] - item) != m.end()) {
            count += m[q[1]-item];
          }
        }
        res.push_back(count);
      }
    }
    return res;
  }
};


class Test {
public:
  void test_coolFeature() {
    Solution sol;
    struct testCase {
      vector<int> a;
      vector<int> b;
      vector<vector<int>> query;
      vector<int> expected;
    };
    vector<testCase> test_cases = {
      {{1,2,3}, {3,4}, {{1,5},{0,0,1},{1,5}}, {2,1}},
      {{1,2,2}, {2,3}, {{1,4},{0,0,3},{1,5}}, {3,4}},
    };
    for(auto&& test_case: test_cases) {
      auto got = sol.coolFeature(test_case.a, test_case.b, test_case.query);
      if (got != test_case.expected) {
        printf("coolFeature(%s, %s, %s) = %s\n",
               CPPUtility::oneDVectorStr<int>(test_case.a).c_str(),
               CPPUtility::oneDVectorStr<int>(test_case.b).c_str(),
               CPPUtility::twoDVectorStr<int>(test_case.query).c_str(),
               CPPUtility::oneDVectorStr<int>(got).c_str());
        assert(false);
      }
    }
  }
};

int main() {
  Test test;
  test.test_coolFeature();
}
