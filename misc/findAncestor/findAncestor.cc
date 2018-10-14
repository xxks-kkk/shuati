#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

// Databricks Phone Interview

// Suppose we have some input data describing a graph of relationships between parents and children over multiple generations. The data is formatted as a list of (parent, child) pairs, where each individual is assigned a unique integer identifier.

// For example, in this diagram, 3 is a child of 1 and 2, and 5 is a child of 4:

// 1   2   4
//  \ /   / \
//   3   5   8
//    \ / \   \
//     6   7   9

// Question:
// Output:
// [
//   [4 2 1],  // node with 0 parent
//   [9,5,7,8] // node with 1 parent
// ]

// Followup:
// Write a function that, for two given individuals in our dataset, returns true if and only if they share at least one ancestor.

// Sample input and output:
// parentChildPairs, 3, 8 => false
// parentChildPairs, 5, 8 => true
// parentChildPairs, 6, 8 => true


vector<vector<int>>
sol(vector<pair<int, int>> &parent_child_pairs);
void
printRes(vector<vector<int>> &res);
bool
findAncestor(vector<pair<int, int>> &parent_child_pairs, int node1, int node2);

// To execute C++, please define "int main()"
int
main()
{
    vector<pair<int, int>> parent_child_pairs = {
        // first: parent
        // second: child
        std::make_pair(1, 3),
        std::make_pair(2, 3),
        std::make_pair(3, 6),
        std::make_pair(5, 6),
        std::make_pair(5, 7),
        std::make_pair(4, 5),
        std::make_pair(4, 8),
        std::make_pair(8, 9)
    };

    auto res = sol(parent_child_pairs);
    printRes(res);

    assert(!findAncestor(parent_child_pairs, 3, 8));
    assert(findAncestor(parent_child_pairs, 5, 8));
    assert(findAncestor(parent_child_pairs, 6, 8));
}

vector<vector<int>>
sol(vector<pair<int, int>> &parent_child_pairs)
{
    vector<vector<int>> res(2, vector<int>());
    unordered_set<int> nodes;
    unordered_map<int, vector<int>> table;
    for (auto &item : parent_child_pairs)
    {
        if (table.find(item.second) == table.end())
        {
            table[item.second] = {item.first};
        }
        else
        {
            table[item.second].push_back(item.first);
        }
        if (nodes.count(item.first) == 0)
        {
            nodes.insert(item.first);
        }
        if (nodes.count(item.second) == 0)
        {
            nodes.insert(item.second);
        }
    }
    for (auto &item : table)
    {
        if (item.second.size() == 1)
        {
            res[1].push_back(item.first);
        }
        if (nodes.count(item.first) == 1)
        {
            nodes.erase(item.first);
        }
    }
    for (auto &item : nodes)
    {
        res[0].push_back(item);
    }
    return res;
}

void
printRes(vector<vector<int>> &res)
{
    for (auto &row : res)
    {
        cout << "[";
        for (auto &item : row)
        {
            cout << item << " ";
        }
        cout << "]" << endl;
    }
}

void
findAncestorHelper(unordered_map<int, vector<int>> &table,
                   unordered_set<int> &nodeset,
                   int node,
                   unordered_set<int> &visited)
{
    if (table.count(node) == 0)
    {
        return;
    }
    for (auto &item : table[node])
    {
        if (visited.count(item) == 0)
        {
            nodeset.insert(item);
            visited.insert(item);
            findAncestorHelper(table, nodeset, item, visited);
        }
    }
}

bool
findAncestor(vector<pair<int, int>> &parent_child_pairs, int node1, int node2)
{
    unordered_map<int, vector<int>> table;
    for (auto &item : parent_child_pairs)
    {
        if (table.find(item.second) == table.end())
        {
            table[item.second] = {item.first};
        }
        else
        {
            table[item.second].push_back(item.first);
        }
    }
    unordered_set<int> node1set;
    unordered_set<int> node2set;
    unordered_set<int> visited;
    findAncestorHelper(table, node1set, node1, visited);
    visited.clear();
    findAncestorHelper(table, node2set, node2, visited);
    for (auto &node : node1set)
    {
        if (node2set.count(node) != 0)
        {
            return true;
        }
    }
    return false;
}



