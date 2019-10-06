#include <vector>
#include "cpputility.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
  int divisorSubstring(int n, int k) {
    string n_str = to_string(n);
    int count = 0;
    vector<int> cands = generate_substr(n_str, k);
    for(auto&& cand: cands) {
      if (cand != 0 && n % cand == 0) count++;
    }
    return count;
  }
private:
  vector<int> generate_substr(string n, int k) {
    vector<int> cands;
    for (int i = 0; i <= n.size()-k; ++i) {
      int num = stoi(n.substr(i,k));
      if (find(cands.begin(), cands.end(), num) == cands.end())
        cands.push_back(num);
    }
    return cands;
  }
};


class Test {
public:
  void test_divisorSubstring() {
    Solution sol;
    struct testCase {
      int n;
      int k;
      int expected;
    };
    vector<testCase> test_cases = {
      {120, 2, 2},
      {555, 1, 1},
    };
    for(auto&& test_case: test_cases) {
      int got = sol.divisorSubstring(test_case.n, test_case.k);
      if (got != test_case.expected) {
        printf("divisorSubstring(%d, %d) = %d\n",
               test_case.n,
               test_case.k,
               got);
        assert(false);
      }
    }
  }
};

int main() {
  Test test;
  test.test_divisorSubstring();
}
