//    Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.
//
//    For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
//
//    Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

#include <vector>

using namespace std;

class Solution
{
public:
    vector<int>
    dailyTemperatures( vector<int> &temperatures )
    {
        int n = temperatures.size();
        vector<int> res(n);
        for (int i = n; i >= 0; i--)
        {
            int j = i+1;
            while(j < temperatures.size() && temperatures[j] <= temperatures[i])
            {
                if (res[j] > 0)
                {
                    j = res[j] + j;
                }
                else
                {
                    j = n;
                }
            }
            // invariant holds once the code reaches here (i.e. right before the following if)
            // either j == n || temperatures[j] > temperatures[i]
            if (j < n)
            {
                res[i] = j - i;
            }
        }
        return res;
    }
};

using ptr2dailyTemperatures = vector<int> ( Solution::* )( vector<int> & );


void
test( ptr2dailyTemperatures pfcn )
{

}


int
main()
{
    ptr2dailyTemperatures pfcn = &Solution::dailyTemperatures;
    test( pfcn );
}