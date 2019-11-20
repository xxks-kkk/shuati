//    There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
//
//    Example 1:
//
//    Input:
//    [
//    "wrt",
//    "wrf",
//    "er",
//    "ett",
//    "rftt"
//    ]
//
//    Output: "wertf"
//    Example 2:
//
//    Input:
//    [
//    "z",
//    "x"
//    ]
//
//    Output: "zx"
//    Example 3:
//
//    Input:
//    [
//    "z",
//    "x",
//    "z"
//    ]
//
//    Output: ""
//
//    Explanation: The order is invalid, so return "".
//    Note:
//
//    You may assume all letters are in lowercase.
//    You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
//    If the order is invalid, return an empty string.
//    There may be multiple valid order of letters, return any one of them is fine.

#include <string>
#include <vector>
#include <cassert>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        string ans;
        if(!words.size()) return ans;

        vector<vector<int>> graph(26, vector<int>()); // directed graph
        unordered_map<int, int> degree; // incoming degree
        if (!buildGraph(words, graph, degree)) return "";
        // topological sorting
        queue<int> Que;
        for(auto elem: degree){
            if(!elem.second) Que.push(elem.first);
        }

        while(!Que.empty()){
            int v = Que.front(); Que.pop();
            ans.push_back(v + 'a');
            for(auto vv: graph[v]){
                degree[vv]--;
                if(!degree[vv]) Que.push(vv);
            }
        }

        for(auto d: degree){ // more edges after topo sort -> circle
            if(d.second > 0) return "";
        }

        return ans;
    }

    bool buildGraph(vector<string> &words, vector<vector<int>> &graph, unordered_map<int, int> &degree){
        for(auto w: words)
        {
            for(auto c: w)
            {
                degree[c - 'a'] = 0;
            }
        }

        for(int i = 1; i < (int)words.size(); i++)
        {
            string pre = words[i - 1];
            string cur = words[i];

            auto pre_size = pre.size();
            auto cur_size = cur.size();
            int j = 0;

            while(j < pre_size && j < cur_size && pre[j] == cur[j])
            {
                j++;
            }

            if(j < pre_size && j == cur_size)
            {
                // e.g. “eb” appears before “e” is invalid
                return false;
            }

            if(j < cur_size && j < pre_size)
            {
                // e.g. "wrt" appears before "wrf" and we get the relation "t -> f"
                graph[pre[j] - 'a'].push_back(cur[j] - 'a'); // add directed edge to graph
                degree[cur[j] - 'a']++;
            }
        }

        return true;
    }
};

using ptr2alienOrder = string (Solution::*)(vector<string>&);

void test(ptr2alienOrder pfcn)
{
    Solution sol;
    vector<string> input = {"wrt", "wrf", "er", "ett", "rftt"};
    assert((sol.*pfcn)(input) == "wertf");
    input = {"e", "eb"};
    assert((sol.*pfcn)(input) == "be");
}

int main()
{
    ptr2alienOrder pfcn = &Solution::alienOrder;
    test(pfcn);
}