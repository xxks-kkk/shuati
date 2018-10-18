//    Given n processes, each process has a unique PID (process id) and its PPID (parent process id).
//
//    Each process only has one parent process, but may have one or more children processes. This is just like a tree structure.
//    Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.
//
//    We use two list of integers to represent a list of processes, where the first list contains PID for each process
//    and the second list contains the corresponding PPID.
//
//    Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes
//    that will be killed in the end. You should assume that when a process is killed, all its children processes will
//    be killed. No order is required for the final answer.
//
//    Example 1:
//    Input:
//    pid =  [1, 3, 10, 5]
//    ppid = [3, 0, 5, 3]
//    kill = 5
//    Output: [5,10]
//    Explanation:
//                3
//              /  \
//            1     5
//                 /
//               10
//    Kill 5 will also kill 10.
//    Note:
//    The given kill id is guaranteed to be one of the given PIDs.
//    n >= 1.

#include <vector>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int>
    killProcess( vector<int> &pid, vector<int> &ppid, int kill )
    {
        vector<int> res;
        // <parent pid, its children pid>
        unordered_map<int, vector<int>> dict;
        for ( auto &id: ppid )
        {
            dict.insert( pair<int, vector<int>>(id, {}) );
        }
        for ( int i = 0; i < pid.size(); ++i )
        {
            dict[ppid[i]].push_back( pid[i] );
        }
        unordered_set<int> visited;
        if ( dict.find( kill ) == dict.end())
        {
            res.push_back( kill );
        }
        else
        {
            res.push_back( kill );
            dfs( dict, kill, res, visited );
        }
        return res;
    }


    void
    dfs( const unordered_map<int, vector<int>> &dict, int target, vector<int> &res, unordered_set<int> &visited )
    {
        if ( dict.find( target ) == dict.end())
        {
            return;
        }
        // C++: std::unordered_map::at returns the corresponding value of the given key in the dictionary
        for ( auto &id : dict.at( target ))
        {
            if ( visited.find( id ) == visited.end())
            {
                visited.emplace( id );
                res.push_back( id );
                dfs( dict, id, res, visited );
            }
        }
    }
};

using ptr2killProcess = vector<int> ( Solution::* )( vector<int> &, vector<int> &, int );


void
test( ptr2killProcess pfcn )
{
    Solution sol;
    vector<int> pid = {1, 3, 10, 5};
    vector<int> ppid = {3, 0, 5, 3};
    int kill = 5;
    unordered_set<int> ans = {5, 10};
    auto res = (sol.*pfcn)( pid, ppid, kill );
    unordered_set<int> res_set( res.begin(), res.end());
    assert ( res_set == ans );

    pid = {1, 2, 3};
    ppid = {0, 1, 2};
    kill = 1;
    ans = {1, 2, 3};
    res = (sol.*pfcn)( pid, ppid, kill );
    unordered_set<int> res_set2( res.begin(), res.end());
    assert( res_set2 == ans );
}


int
main()
{
    ptr2killProcess pfcn = &Solution::killProcess;
    test( pfcn );
}