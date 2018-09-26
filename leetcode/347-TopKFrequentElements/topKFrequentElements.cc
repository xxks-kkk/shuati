//    Given a non-empty array of integers, return the k most frequent elements.
//
//    Example 1:
//
//    Input: nums = [1,1,1,2,2,3], k = 2
//    Output: [1,2]
//    Example 2:
//
//    Input: nums = [1], k = 1
//    Output: [1]
//    Note:
//
//    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

#include <vector>
#include <cassert>
#include <queue>      // std::priority_queue
#include <functional> // std::greater
#include <unordered_map>
#include <list>

using namespace std;

class Solution
{
public:
    // Solution1: We use priority queue
    vector<int>
    topKFrequent( vector<int> &nums, int k )
    {
        unordered_map<int, int> table;
        list<int> res;
        for(auto& num : nums)
        {
            table[num]++;
        }
        // use min-heap
        // how to think: whether the incoming element greater than the top of the heap?
        //               If yes, move the incoming element below the top element
        //               If no, incoming element becomes new top element
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto& element: table)
        {
            // (count, key) pair; min-heap is built based on 'count'
            pq.push({element.second, element.first});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        assert(pq.size() == k);
        while(!pq.empty())
        {
            res.push_front(pq.top().second);
            pq.pop();
        }
        // use make_move_iterator to move elements from list to vector
        // https://stackoverflow.com/questions/5218713/one-liner-to-convert-from-listt-to-vectort
        return {make_move_iterator(begin(res)), make_move_iterator(end(res))};
    }
};

using ptr2topKFrequent = vector<int> ( Solution::* )( vector<int> &, int );


void
test( ptr2topKFrequent pfcn )
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> ans = {1, 2};
    int k = 2;
    assert((sol.*pfcn)( nums, k ) == ans );

    nums = {1};
    k = 1;
    ans = {1};
    assert((sol.*pfcn)( nums, k ) == ans );
}


int
main()
{
    ptr2topKFrequent pfcn = &Solution::topKFrequent;
    test( pfcn );
}