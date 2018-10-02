// http://www.1point3acres.com/bbs/thread-446284-1-1.html
#include <string>
#include <unordered_map>
#include <climits>
#include <cassert>

using namespace std;

class Solution
{
public:
    int
    differentTeams(string skills)
    {
        unordered_map<char, int> table;
        for(auto& c: skills)
        {
            table[c]++;
        }
        int minVal = INT_MAX;
        for(auto& item : table)
        {
            minVal = min(item.second, minVal);
        }
        return minVal;
    }
};

using ptr2differentTeams = int (Solution::*)(string);

void
test(ptr2differentTeams pfcn)
{
    Solution sol;
    string skills = "pcmbzpcmbz";
    assert((sol.*pfcn)(skills) == 2);
}

int
main()
{
    ptr2differentTeams pfcn = &Solution::differentTeams;
    test(pfcn);
}