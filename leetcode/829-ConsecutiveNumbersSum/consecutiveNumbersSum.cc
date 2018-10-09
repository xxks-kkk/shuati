#include <cassert>
#include <cmath>

class Solution
{
public:
    int
    consecutiveNumbersSum(int N)
    {
        // Solution is slightly different than the reference
        // x + (x+1) + ... +(x+k) = N
        // kx + (1+k)k/2 = N
        // kx = N - (1+k)k/2
        // With this setup, we set count = 0 and k starts with 1
        int count = 0;
        for(int k = 1; k < sqrt(2*N); ++k)
        {
            if ((N - (1+k)*k/2) % k == 0)
            {
                count++;
            }
        }
        return count;
    }
};

using ptr2consecutiveNumbersSum = int (Solution::*)(int);

void
test(ptr2consecutiveNumbersSum pfcn)
{
    Solution sol;
    assert((sol.*pfcn)(5) == 2);
    assert((sol.*pfcn)(9) == 3);
    assert((sol.*pfcn)(15) == 4);
}

int
main()
{
    ptr2consecutiveNumbersSum pfcn = &Solution::consecutiveNumbersSum;
    test(pfcn);
}