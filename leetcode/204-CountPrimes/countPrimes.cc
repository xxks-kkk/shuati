//    Count the number of prime numbers less than a non-negative number, n.
//
//    Example:
//
//    Input: 10
//    Output: 4
//    Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    // Method: The Sieve of Eratosthenes (http://mathforum.org/dr.math/faq/faq.prime.num.html)
    int countPrimes(int n) {
        vector<bool> notPrime (n, false);
        int count = 0;
        // i < n b/c we are asked to count number of prime number "smaller than" n
        for(int i = 2; i < n; ++i)
        {
            if (notPrime[i] == false)
            {
                count++;
                for(int j = 2; i*j < n; ++j)
                {
                    notPrime[i*j] = true;
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
    int n = 10;
    assert((sol.*pfcn)(n) == 4);
    n = 11;
    assert((sol.*pfcn)(n) == 4);
}

int main()
{
    ptr2countPrimes pfcn = &Solution::countPrimes;
    test(pfcn);
}