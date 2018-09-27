#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        queue<char> q;
        int start = 0;
        for(auto& c: chars)
        {
            q.push(c);
        }
        while(!q.empty())
        {
            char c = q.front();
            q.pop();
            chars[start] = c;
            start++;
            int count = 1;
            while(q.front() == c)
            {
                q.pop();
                count++;
            }
            if (count > 1)
            {
                auto vec = convert(count);
                int j = 0;
                for(; j < vec.size(); ++j, ++start)
                {
                    chars[start] = vec[j];
                }
            }
        }
        return start;
    }

    // Optimized solution: two pointers
    int compress2(vector<char>& chars) {
        int start = 0;
        // count the length of the same characters
        int count = 0;
        for(int end = 0; end < chars.size(); ++end)
        {
            count++;
            if (end == chars.size() - 1 || chars[end] != chars[end+1])
            {
                chars[start] = chars[end];
                start++;
                if (count > 1)
                {
                    auto vec = convert(count);
                    int j = 0;
                    for(; j < vec.size(); ++j, ++start)
                    {
                        chars[start] = vec[j];
                    }
                }
                count = 0;
            }
        }
        return start;
    }
private:
    vector<char> convert(int count)
    {
        // convert int into a vector of char
        list<char> res;
        while(count > 0)
        {
            res.push_front(to_string(count%10)[0]);
            count = count/10;
        }
        return vector<char>{make_move_iterator(res.begin()), make_move_iterator(res.end())};
    }
};

using ptr2compress = int (Solution::*)(vector<char>&);

void test(ptr2compress pfcn)
{
    Solution sol;
    vector<char> input = {'a','a','b','b','c','c','c'};
    int res = (sol.*pfcn)(input);
    assert(res == 6);
    vector<char> ans = {'a','2','b','2','c','3'};
    for(int i = 0; i < ans.size(); ++i)
    {
        assert(ans[i] == input[i]);
    }

    input = {'a','a','a','b','b','a','a'};
    res = (sol.*pfcn)(input);
    assert(res == 6);
    ans = {'a','3','b','2','a','2'};
    for(int i = 0; i < ans.size(); ++i)
    {
        assert(ans[i] == input[i]);
    }
}

int main()
{
    ptr2compress pfcn = &Solution::compress;
    test(pfcn);
    pfcn = &Solution::compress2;
    test(pfcn);
}