#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int fib(int N) {
        int res = 0;
        int prev = 0, curr = 1;
        if (N == 0) return prev;
        if (N == 1) return curr;
        for(int i = 2; i <= N; ++i) {
            res = (prev + curr);
            prev = curr;
            curr = res;
        }
        return res;
    }
};

using ptr2fib = int (Solution::*)(int);

void test(ptr2fib pfcn) {
  Solution sol;
  struct testCase {
    int N;
    int expected;
  };
  vector<testCase> test_cases = {
    {2, 1},
    {3, 2},
  };
  for(auto&& test_case: test_cases) {
    auto got = (sol.*pfcn)(test_case.N);
    if (got != test_case.expected) {
      printf("fib(%d) = %d\n",
             test_case.N,
             got);
      assert(false);
    }
  }
}

int main() {
  ptr2fib pfcn = &Solution::fib;
  test(pfcn);
}
