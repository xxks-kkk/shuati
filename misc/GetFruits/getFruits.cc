// Google 2019 OA
// LC-159 variant
// http://www.1point3acres.com/bbs/thread-438475-1-1.html

#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int
    getFruits( const vector<int> &fruits )
    {
        int max_len = 1;
        int start = 0;
        unordered_map<int, int> dict;
        int count = 0;
        for(int i = 0; i < fruits.size(); ++i)
        {
            dict[fruits[i]]++;
            if (dict[fruits[i]] == 1)
            {
                // we encounter a new int
                count++;
                while(count > 2)
                {
                    dict[fruits[start]]--;
                    if (dict[fruits[start]] == 0)
                    {
                        count--;
                    }
                    start++;
                }
            }
            max_len = max(max_len, i-start+1);
        }
        return max_len;
    }
};

using ptr2getFruits = int ( Solution::* )( const vector<int> & );


void
test(ptr2getFruits pfcn)
{
    Solution sol;
    vector<int> fruits = {1,2,1,3,4,3,5,1,2};
    assert((sol.*pfcn)(fruits) == 3);
    fruits = {1,2,1,2,1,2,1};
    assert((sol.*pfcn)(fruits) == 7);
}


int
main()
{
    ptr2getFruits pfcn = &Solution::getFruits;
    test(pfcn);
}
