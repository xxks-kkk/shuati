/*************************************************************************
  > File Name:       longestConsecutiveSequence.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/30/18
  > Description:
    
    Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

    Your algorithm should run in O(n) complexity.

    Example:

    Input: [100, 4, 200, 1, 3, 2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 ************************************************************************/

#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;

class Solution
{
public:
    int
    longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        int max_length = 0;
        for(auto& num : nums)
        {
            s.insert(num);
        }
        for(auto& num : s)
        {
            // We have to make sure that the `num` is the beginning
            // of the consecutive elements sequence. Otherwise, we can
            // always include `num-1` to make a longer consecutive elements sequence
            if(s.find(num-1) == s.end())
            {
                int currNum = num;
                int currLength = 1;
                while(s.find(currNum+1) != s.end())
                {
                    currNum++;
                    currLength++;
                }
                max_length = max(max_length, currLength);
            }
        }
        return max_length;
    }
};

using ptr2longestConsecutive = int (Solution::*)(vector<int>& num);

void test(ptr2longestConsecutive pfcn)
{
    Solution sol;
    vector<int> num = {100, 4, 200, 1, 3, 2};
    assert((sol.*pfcn)(num) == 4);
}

int main()
{
    ptr2longestConsecutive pfcn = &Solution::longestConsecutive;
    test(pfcn);
}