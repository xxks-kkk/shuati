// http://www.1point3acres.com/bbs/thread-446284-1-1.html
// http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=446267&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26sortid%3D311
// Similar to LC39

#include <vector>
#include <string>
#include <cassert>
#include <sstream>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string> findSchedules(int work_hours, int day_hours, string pattern)
    {
        int given_hours = 0;
        vector<int> emptySpots;
        vector<string> ret;
        for(int i = 0; i < pattern.length(); ++i)
        {
            if (pattern[i] != '?')
            {
                given_hours += pattern[i] - '0';
            }
            else
            {
                emptySpots.push_back(i);
            }
        }
        int target_hour = work_hours - given_hours;
        vector<int> num(target_hour+1);
        for(int i = 0; i < num.size(); ++i)
        {
            num[i] = i;
        }
        vector<vector<int>> res;
        vector<int> path;
        dfs(num, target_hour, emptySpots.size(), path, res);
        for(auto& vec : res)
        {
            ret.push_back(constructRes(vec, pattern, emptySpots));
        }
        return ret;
    }
private:
    void dfs(vector<int>& num, int target_hour, const int emptySpots, vector<int>& path, vector<vector<int>>& res)
    {
        if (target_hour < 0)
        {
            return;
        }
        if (target_hour == 0)
        {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < num.size(); ++i)
        {
            // i starts with 0, which guarantee that the order will be lexicographically
            path.push_back(num[i]);
            if (path.size() <= emptySpots)
            {
                dfs(num, target_hour-num[i], emptySpots, path, res);
            }
            path.pop_back();
        }
    }

    string constructRes(vector<int> path, string pattern, vector<int>& emptySpots)
    {
        // We fill in the the short path (e.g. 4) with trailing 0s to make it have
        // the length as the number of empty spots (e.g. 40).
        if (path.size() < emptySpots.size())
        {
            for(int i = 0; i < emptySpots.size() - path.size(); ++i)
            {
                path.push_back(0);
            }
        }
        for(int i = 0; i < path.size(); ++i)
        {
            pattern[emptySpots[i]] = '0' + path[i];
        }
        return pattern;
    }
};

using ptr2findSchedules = vector<string> (Solution::*)(int, int, string);

void test(ptr2findSchedules pfcn)
{
    Solution sol;
    string pattern = "08??840";
    int work_hours = 24;
    int day_hours = 4;
    vector<string> ans = {
        "0804840",
        "0813840",
        "0822840",
        "0831840",
        "0840840"
    };
    assert((sol.*pfcn)(work_hours, day_hours, pattern) == ans);
}

int main()
{
    ptr2findSchedules pfcn = &Solution::findSchedules;
    test(pfcn);
}