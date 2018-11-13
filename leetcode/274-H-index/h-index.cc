//    Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute
//    the researcher's h-index.
//
//    According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at
//    least h citations each, and the other N − h papers have no more than h citations each."
//
//    Example:
//
//    Input: citations = [3,0,6,1,5]
//    Output: 3
//    Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had
//        received 3, 0, 6, 1, 5 citations respectively.
//    Since the researcher has 3 papers with at least 3 citations each and the remaining
//    two with no more than 3 citations each, her h-index is 3.
//    Note: If there are several possible values for h, the maximum one is taken as the h-index.

#include <vector>
#include <cassert>

using namespace std;

class Solution
{
public:
    // Solution 1: Sort
    // runtime: O(nlogn)
    int
    hIndex(vector<int> &citations)
    {
        // Sort in the descending order
        sort(citations.rbegin(), citations.rend());
        int i;
        for (i = 0; i < citations.size(); ++i)
        {
            // We try to find the largest i s.t. citations[i] > i
            if (citations[i] <= i)
            {
                break;
            }
        }
        return i;
    }

    // Solution 2: Counting sort
    int
    hIndex2(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> papers(n+1);
        // counting papers for each citation number
        // Intuition: any citation larger than n can be replaced by n and the h-index will not change after
        // the replacement (i.e., h-index is upper-bounded by total number of papers n)
        for(int c: citations)
        {
            papers[min(n,c)]++;
        }
        // find the h-index
        // s = the number of papers with citation >= k
        // h-index = k where s >= k
        int k = n;
        for(int s = papers[n]; k > s; s += papers[k])
        {
            k--;
        }
        return k;
    }
};
using ptr2hIndex = int (Solution::*)(vector<int> &);

void
test(ptr2hIndex pfcn)
{
    Solution sol;
    vector<int> citations = {3,0,6,1,5};
    assert((sol.*pfcn)(citations) == 3);
}

int
main()
{
    ptr2hIndex pfcn = &Solution::hIndex;
    test(pfcn);

    pfcn = &Solution::hIndex2;
    test(pfcn);
}