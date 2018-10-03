#include <vector>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numberOfPairs(vector<int>&a, int k)
    {
        int count = 0;
        unordered_map<int,int> bag;
        unordered_map<int,int> table;
        for(auto& item : a)
        {
            if (table.find(k-item) != table.end())
            {
                if(bag.count(item) == 0 and bag.count(k-item) == 0)
                {
                    bag[item] = k-item;
                    count += 1;
                }
            }
            table[item] = 0;
        }
        return count;
    }
};

using ptr2numberOfPairs = int (Solution::*)(vector<int>&, int);

void test(ptr2numberOfPairs pfcn)
{
    Solution sol;
    vector<int> a = {1,2,3,6,7,8,9,1};
    int k = 10;
    assert((sol.*pfcn)(a, k) == 3);

    a = {1,3,46,1,3,9};
    k = 47;
    assert((sol.*pfcn)(a,k) == 1);
}

int main()
{
    ptr2numberOfPairs pfcn = &Solution::numberOfPairs;
    test(pfcn);
}