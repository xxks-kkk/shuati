//    Count the number of prime numbers less than a non-negative number, n.
//
//    Example:
//
//    Input: 10
//    Output: 4
//    Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

#include <cassert>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    // is_prime[i] represents if i is prime or not. Initially, set each to true.
    // excepting 0 and 1 (ignore for now). Then use sieving to eliminate nonprime.
    deque<bool> is_prime (n, true);
    int count = 0;
    // i < n b/c we are asked to count number of prime number "smaller than" n
    for(int i = 2; i < n; ++i)
    {
      if (is_prime[i])
      {
        count++;
        // Sieve i's multiples.
        for(int j = i; j < n; j+=i)
        {
          is_prime[j] = false;
        }
      }
    }
    return count;
  }
};

using ptr2countPrimes = int (Solution::*)(int);

void test(ptr2countPrimes pfcn)
{
    Solution sol;
    struct testCase {
      int n;
      int expected;
    };
    vector<testCase> test_cases = {
      {10, 4},
      {11, 4}
    };
    for(auto&& test_case: test_cases) {
      auto got = (sol.*pfcn)(test_case.n);
      if (got != test_case.expected) {
        printf("countPrimes(%d) = %d\n",
               test_case.n,
               test_case.expected);
        assert(false);
      }
    }
}

int main()
{
    ptr2countPrimes pfcn = &Solution::countPrimes;
    test(pfcn);
}
