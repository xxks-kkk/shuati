// http://likemyblogger.blogspot.com/2016/02/mj-53-tree-s-expression.html
// http://massivealgorithms.blogspot.com/2016/05/tree-s-expression.html
// http://www.1point3acres.com/bbs/thread-131422-1-1.html

#include <string>
#include <cassert>
#include <vector>
#include <map>
#include <sstream>
#include <unordered_set>
#include <stack>
#include <iostream>

using namespace std;

class Solution
{
public:
    // My attempt
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
        int numVertices = 0;
        bool error = false;
        map<string, vector<string>> graph = parseNodes(nodes, numVertices, error);
        if (error)
        {
            return error_code[4]; // E5
        }
        return generateSExpression(error_code, graph, numVertices);
    }

private:
    map<string, vector<string>>
    parseNodes(string nodes, int &numVertices, bool &error)
    {
        map<string, vector<string>> graph;
        stringstream ss(nodes);
        string token;
        unordered_set<string> vertex;
        while (getline(ss, token, ' '))
        {
            if (token.length() != 5)
            {
                error = true;
                return graph;
            }
            string first = string(1, token[1]);
            string second = string(1, token[3]);
            if (!vertex.count(first))
            {
                vertex.insert(first);
            }
            if (!vertex.count(second))
            {
                vertex.insert(second);
            }
            if (graph.find(first) != graph.end())
            {
                graph[first].push_back(second);
            }
            else
            {
                graph[first] = {second};
            }
        }
        for (auto &item : graph)
        {
            sort(item.second.begin(), item.second.end());
        }
        numVertices = vertex.size();
        return graph;
    }

    string
    generateSExpression(const vector<string> &error_code, map<string, vector<string>> &graph, int numVertices)
    {
        stringstream ss;
        unordered_set<string> visited;
        stack<string> st;
        // keep tracking of # of pop we have done
        int counter = 0;
        // maintain a set of vertex that has incoming edge
        unordered_set<string> incomingEdges;
        // assume the begin() is the smallest element ('A')
        st.push(graph.begin()->first);
        while (!st.empty())
        {
            auto item = st.top();
            st.pop();
            counter++;
            if (graph[item].size() > 2)
            {
                return error_code[0]; // E1
            }
            ss << "(" << item;
            visited.insert(item);
            if (graph[item].size() == 0)
            {
                // we reach the child of the tree
                while (counter > st.size())
                {
                    counter--;
                    ss << ")";
                }
            }
            // assume vector is ordered like [B,C]
            for (int i = graph[item].size() - 1; i >= 0; --i)
            {
                if (visited.count(graph[item][i]))
                {
                    return error_code[2]; // E3
                }
                if (graph.find(graph[item][i]) != graph.end() &&
                    find(graph[graph[item][i]].begin(), graph[graph[item][i]].end(), item) !=
                        graph[graph[item][i]].end())
                {
                    return error_code[1]; // E2
                }
                incomingEdges.insert(graph[item][i]);
                st.push(graph[item][i]);
            }
            cout << "IncomingEdges size: " << incomingEdges.size() << endl;
        }
        cout << "numVertices: " << numVertices << endl;
        cout << "IncomingEdges size: " << incomingEdges.size() << endl;
        if (incomingEdges.size() < (numVertices - 1))
        {
            return error_code[3]; // E4
        }
        cout << "string: " << ss.str();
        return ss.str();
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

    nodes = "(A,B) (B,A)";
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