//    Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
//
//    Note:
//
//    The same word in the dictionary may be reused multiple times in the segmentation.
//    You may assume the dictionary does not contain duplicate words.
//    Example 1:
//
//    Input:
//    s = "catsanddog"
//    wordDict = ["cat", "cats", "and", "sand", "dog"]
//    Output:
//    [
//    "cats and dog",
//    "cat sand dog"
//    ]
//    Example 2:
//
//    Input:
//    s = "pineapplepenapple"
//    wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
//    Output:
//    [
//    "pine apple pen apple",
//    "pineapple pen apple",
//    "pine applepen apple"
//    ]
//    Explanation: Note that you are allowed to reuse a dictionary word.
//    Example 3:
//
//    Input:
//    s = "catsandog"
//    wordDict = ["cats", "dog", "sand", "and", "cat"]
//    Output:
//    []

#include <string>
#include <vector>
#include <cassert>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    // DP solution
    vector<string>
    wordBreak(string s, vector<string> &wordDict)
    {
        // before we jump into DP, we need to first verify that
        // whether s is breakable (i.e., there exists at least one solution to the problem)
        set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp1(s.length() + 1);
        dp1[0] = true;
        for (int i = 1; i < dp1.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp1[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end())
                {
                    dp1[i] = true;
                    break;
                }
            }
        }
        // We're done if there is no breakable solution for s
        if (!dp1[s.length()])
        {
            return {};
        }

        // dp[i] = all the valid word breaks for s[0, i]
        vector<vector<string>> dp(s.length() + 1);
        // Note: dp[0].size() > 0
        dp[0] = {""};
        for (int i = 1; i < dp.size(); ++i)
        {
            vector<string> tmp;
            // The idea is that dp[i] = dp[j] + s[i,j] (we append s[i,j] to all the possible strings in dp[j] for 0 <= j < i) if
            // s[i,j] is part of the wordDict
            for (int j = 0; j < i; ++j)
            {
                if (dp[j].size() > 0 && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
                {
                    for (auto &cand: dp[j])
                    {
                        tmp.push_back(cand + ((cand == "") ? "" : " ") + s.substr(j, i - j));
                    }
                }
            }
            dp[i] = tmp;
        }
        return dp[s.length()];
    }

    // DFS Solution
    vector<string>
    wordBreak2(string s, vector<string> &wordDict)
    {
        unordered_map<string, vector<string>> memo;
        return wordBreak2Helper(s, memo, wordDict);
    }

private:
    vector<string>
    wordBreak2Helper(string s, unordered_map<string, vector<string>>& memo, vector<string>& wordDict)
    {
        if (s.length() == 0)
        {
            return {};
        }
        if (memo.find(s) != memo.end())
        {
            return memo[s];
        }
        vector<string> res;
        for(auto& word: wordDict)
        {
            if (s.substr(0, word.length()) != word)
            {
                continue;
            }
            if (s.length() == word.length())
            {
                res.push_back(s);
            }
            else
            {
                auto rest = wordBreak2Helper(s.substr(word.length()), memo, wordDict);
                for (auto& item : rest)
                {
                    string tmp = word + " " + item;
                    res.push_back(tmp);
                }
            }
        }
        memo[s] = res;
        return res;
    }
};

using ptr2wordBreak = vector<string> (Solution::*)(string, vector<string> &);

void
test(ptr2wordBreak pfcn)
{
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    unordered_set<string> ans = {"cats and dog", "cat sand dog"};
    vector<string> res = (sol.*pfcn)(s, wordDict);
    unordered_set<string> res_set(res.begin(), res.end());
    assert(res_set == ans);

    s = "pineapplepenapple";
    wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    ans = {"pine apple pen apple", "pineapple pen apple", "pine applepen apple"};
    res = (sol.*pfcn)(s, wordDict);
    res_set = unordered_set<string>(res.begin(), res.end());
    assert(res_set == ans);

    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    ans = {};
    res = (sol.*pfcn)(s, wordDict);
    res_set = unordered_set<string>(res.begin(), res.end());
    assert( res_set == ans);
}

int
main()
{
    ptr2wordBreak pfcn = &Solution::wordBreak;
    test(pfcn);

    pfcn = &Solution::wordBreak2;
    test(pfcn);
}