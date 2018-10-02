// http://www.1point3acres.com/bbs/thread-446266-1-1.html
// Similar to LC829
#include <cmath>
#include <cassert>

using namespace std;

class Solution
{
public:
    int consecutive(long num)
    {
        int count = 0; // Unlike LC829, `num` itself doesn't count as a way (e.g. 5 = 5)
        for( int k = 2; k < sqrt( 2 * num ); k++ ) {
            if ( ( num - ( k * ( k - 1 )/2) ) % k == 0) count++;
        }
        return count;
    }
};

using ptr2consecutive = int (Solution::*)(long);

void test(ptr2consecutive pfcn)
{
    Solution sol;
    assert((sol.*pfcn)(15) == 3);
}

int main()
{
    ptr2consecutive pfcn = &Solution::consecutive;
    test(pfcn);
}