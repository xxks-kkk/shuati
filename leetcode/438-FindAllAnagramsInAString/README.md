## Solution explanation

The following solution may lead to timeout for the extreme case: s = "aaaa...a", 
p = "aaaaaa...a":

```cpp
vector<int>
findAnagrams(string s, string p)
{
    if (p.length() > s.length())
    {
        return {};
    }
    vector<int> res;
    unordered_map<char, int> table;
    for (auto &c: p)
    {
        table[c]++;
    }
    for (int i = 0; i < s.length() - p.length() + 1; ++i)
    {
        unordered_map<char, int> tmp;
        int j;
        for (j = i; j < i + p.length(); ++j)
        {
            if (table.find(s[j]) == table.end())
            {
                break;
            }
            else
            {
                tmp[s[j]]++;
                if (tmp[s[j]] > table[s[j]])
                {
                    break;
                }
            }
        }
        if (tmp == table)
        {
            res.push_back(i);
        }
    }
    return res;
}
```

To improve the efficiency, sliding window approach is the way to go.

## Reference

- https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92027/C%2B%2B-O(n)-sliding-window-concise-solution-with-explanation