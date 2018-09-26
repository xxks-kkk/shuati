#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // key: char
        // value: <count, index of the character>
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

    int firstUniqChar2(string s) {
        // <character, <index, count>>
        unordered_map<char, pair<int, int>> table;
        for(int i = 0; i < s.size(); ++i)
        {
            if (table.find(s[i]) == table.end())
            {
                table[s[i]] = {i, 1};
            }
            else
            {
                table[s[i]].first = i;
                table[s[i]].second++;
            }
        }
        int idx = s.length();
        for(auto& item: table)
        {
            if(item.second.second == 1)
            {
                idx = min(idx, item.second.first);
            }
        }
        return idx == s.length()? -1: idx;
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
    s = "cc";
    assert((sol.*pfcn)(s) == -1);
}

int main()
{
    ptr2firstUniqChar pfcn = &Solution::firstUniqChar2;
    test(pfcn);
}