//    Given a non-empty array of integers, return the third maximum number in this array. If it does not exist,
//    return the maximum number. The time complexity must be in O(n).
//
//    Example 1:
//    Input: [3, 2, 1]
//
//    Output: 1
//
//    Explanation: The third maximum is 1.
//    Example 2:
//    Input: [1, 2]
//
//    Output: 2
//
//    Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
//    Example 3:
//    Input: [2, 2, 3, 1]
//
//    Output: 1
//
//    Explanation: Note that the third maximum here means the third maximum distinct number.
//    Both numbers with value 2 are both considered as second maximum.

#include <vector>
#include <set>
#include <cassert>

using namespace std;

class Solution
{
public:
    int
    thirdMax( vector<int> &nums )
    {
        // about set: if nums = [3,2,1], then after insertion of all elements, set internally becomes [1,2,3] with
        // s.begin() points at 1. If set<int, greater<int>> s; then after insertion of all elements, set becomes [3,2,1]
        // s.begin() points at 3. By default, set is defined as set<T, less<T>>
        // how to think:
        // - if greater<T>, letmost element is the greatest
        // - if less<T>, leftmost element is the smallest
        set<int> s;
        for(auto& num : nums)
        {
            s.insert(num);
            if (s.size() > 3)
            {
                s.erase(s.begin());
            }
        }
        // rbegin(): a reverse iterator pointing to the last element in the container
        // Note not end() because iterator referring to the *past-the-end* element in the set container.
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};

using ptr2thridMax = int (Solution::*)(vector<int>&);

void test(ptr2thridMax pfcn)
{
    Solution sol;
    vector<int> input = {3,2,1};
    assert((sol.*pfcn)(input) == 1);

    input = {1,2};
    assert((sol.*pfcn)(input) == 2);

    input = {2,2,3,1};
    assert((sol.*pfcn)(input) == 1);
}

int main()
{
    ptr2thridMax pfcn = &Solution::thirdMax;
    test(pfcn);
}