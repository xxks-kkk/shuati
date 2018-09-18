#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // key: char
        // value: <count, index of the character
        unordered_map<char, pair<int, int>> dict;
        int idx = s.length();
        for(int i = 0; i < s.length(); ++i)
        {
            dict[s[i]].first++;
            dict[s[i]].second = i;
        }
        for(auto & item: dict)
        {
            if (item.second.first == 1)
            {
                idx = min(idx, item.second.second);
            }
        }
        return idx == s.length() ? -1 : idx;
    }
};

using ptr2firstUniqChar = int (Solution::*)(string);

void test(ptr2firstUniqChar pfcn)
{
    Solution sol;
    string s = "leetcode";
    assert((sol.*pfcn)(s) == 0);
    s = "loveleetcode";
    assert((sol.*pfcn)(s) == 2);
}

int main()
{

}