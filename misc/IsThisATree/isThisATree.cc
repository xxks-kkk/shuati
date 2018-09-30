// http://likemyblogger.blogspot.com/2016/02/mj-53-tree-s-expression.html
// http://massivealgorithms.blogspot.com/2016/05/tree-s-expression.html
// |- https://github.com/xieqilu/Qilu-leetcode/blob/master/B219.GetSExpressionBT.cs
// http://www.1point3acres.com/bbs/thread-131422-1-1.html

// Citadel OA 2019

#include <string>
#include <cassert>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_set>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    string
    SExpression(string nodes)
    {
        vector<string> error_code = {
            "E1 More than 2 children", //0
            "E2 Duplicate Edges",      //1
            "E3 Cycle present",        //2
            "E4 Multiple roots",       //3
            "E5 Any other error"       //4   // could be the case where a node has multiple parents
        };
        auto group = parseNodes(error_code, nodes);
        if (!group.second.empty())
        {
            // there is error message during the process of the given nodes
            return group.second;
        }
        auto graph = group.first;
        assert(graph.size() != 0);

        // search for the root
        string root = "";
        for (auto& item : graph)
        {
            // check if a node has parent
            if (item.second.first.empty())
            {
                if (!root.empty())
                {
                    // E3
                    return error_code[3];
                }
                else
                {
                    root = item.first;
                }
            }
        }
        if (root.empty())
        {
            // No root => cycle exists
            // E3
            return error_code[2];
        }

        // check for cycles
        unordered_set<string> seen;
        queue<string> layer;
        layer.push(root);
        while(!layer.empty())
        {
            auto node = layer.front();
            layer.pop();
            if(seen.count(node))
            {
                // E3
                return error_code[2];
            }
            seen.insert(node);
            for(auto& child : graph[node].second)
            {
                layer.push(child);
            }
        }

        // generate S-expression
        return generateSExpression(graph, root);
    }

private:
    pair<map<string, pair<string, vector<string>>>, string>
    parseNodes(vector<string> &error_code, string &nodes)
    {
        // key: node
        // vale: (node's parent, a vector of its children)
        map<string, pair<string, vector<string>>> graph;
        stringstream ss(nodes);
        string token;
        // keep track of the edges we have processed so far
        vector<pair<string, string>> edges;
        while (getline(ss, token, ' '))
        {
            string first = string(1, token[1]);
            string second = string(1, token[3]);
            if (!isupper(first[0]) || !isalpha(first[0]) || !isalpha(second[0]) || !isupper(second[0]))
            {
                // E5
                return make_pair(graph, error_code[4]);
            }
            auto edge = make_pair(first, second);
            if (find(edges.begin(), edges.end(),edge) != edges.end())
            {
                // E2
                return make_pair(graph, error_code[1]);
            }
            edges.push_back(edge);
            if (graph.find(first) != graph.end())
            {
                graph[first].second.push_back(second);
                if (graph[first].second.size() > 2)
                {
                    // E1
                    return make_pair(graph, error_code[0]);
                }
            }
            else
            {
                graph[first] = make_pair("", vector<string>{second});
            }
            if (graph.count(second))
            {
                // when there are multiple parents for a node, we simply overriding here instead of return some error
                // message. Here, the tree is a rather generic term in graph => can have multiple parents.
                graph[second].first = first;
            }
            else
            {
                graph[second] = make_pair(first, vector<string>{});
            }
        }
        for (auto &item : graph)
        {
            sort(item.second.second.begin(), item.second.second.end());
        }
        return make_pair(graph, "");
    }

    string
    generateSExpression(map<string, pair<string, vector<string>>>& graph, string root)
    {
        if (graph[root].second.empty())
        {
            return "(" + root + ")";
        }
        auto comp1 = generateSExpression(graph, graph[root].second[0]);
        if (graph[root].second.size() == 1)
        {
            return "(" + root + comp1 + ")";
        }
        else
        {
            auto comp2 = generateSExpression(graph, graph[root].second[1]);
            return "(" + root + comp1 + comp2 + ")";
        }
    }
};

using ptr2SEexpression = string (Solution::*)(string);

void
test(ptr2SEexpression pfcn)
{
    Solution sol;
    string nodes = "(B,D) (D,E) (A,B) (C,F) (E,G) (A,C)";
    string ans = "(A(B(D(E(G))))(C(F)))";
    assert((sol.*pfcn)(nodes) == ans);

    nodes = "(A,B) (A,C) (A,D)";
    ans = "E1 More than 2 children";
    assert((sol.*pfcn)(nodes) == ans);

    nodes = "(A,B) (A,B)";
    ans = "E2 Duplicate Edges";
    assert((sol.*pfcn)(nodes) == ans);

    nodes = "(A,B) (B,C) (C,A)";
    ans = "E3 Cycle present";
    assert((sol.*pfcn)(nodes) == ans);

    nodes = "(A,C) (B,C)";
    ans = "E4 Multiple roots";
    assert((sol.*pfcn)(nodes) == ans);

    nodes = "(A,B) (A,C) (B,D) (D,C)";
    ans = "E3 Cycle present";
    assert((sol.*pfcn)(nodes) == ans);

    nodes = "(B,A) (B,C) (A,D)";
    ans = "(B(A(D))(C))";
    assert((sol.*pfcn)(nodes) == ans);
}

int
main()
{
    ptr2SEexpression pfcn = &Solution::SExpression;
    test(pfcn);
}