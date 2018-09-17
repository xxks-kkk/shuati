// http://www.1point3acres.com/bbs/thread-439073-2-1.html
// Must be solved using DP
// Similar to CodeForce Problem 13 (http://codeforces.com/problemset/problem/13/C)
// The following solution is based on priority queue, which can pass 8/13 test cases
// Referece: https://www.geeksforgeeks.org/minimum-incrementdecrement-to-make-array-non-increasing/
// TODO: implement DP solution; benchmark performance under large size slope

#include <vector>
#include <queue>
#include <cassert>

using namespace std;

long climbTheHill(vector<int> slope)
{
    int costDecrease = 0;
    int costIncrease = 0;
    int diff = 0;
    unsigned long n = slope.size();

    // min heap
    priority_queue<int, vector<int>, greater<int> > pq;

    // Here in the loop we will
    // check that whether the upcoming
    // element of array is less than top
    // of priority queue. If yes then we
    // calculate the difference. After
    // that we will remove that element
    // and push the current element in
    // queue. And the sum is incremented
    // by the value of difference
    for (int i = 0; i < n; ++i) {
        if (!pq.empty() && pq.top() < slope[i]) {
            diff = slope[i] - pq.top();
            costDecrease += diff;
            pq.pop();
            pq.push(slope[i]);
        }
        pq.push(slope[i]);
    }

    // max heap
    priority_queue<int, vector<int>, less<int> >pq2;

    for (int i = 0; i < n; ++i)
    {
        if (!pq2.empty() && pq2.top() > slope[i]) {
            diff = pq2.top() - slope[i];
            costIncrease += diff;
            pq2.pop();
            pq2.push(slope[i]);
        }
        pq2.push(slope[i]);
    }

    return min(costIncrease, costDecrease);
}

void test()
{
    vector<int> slope = {0,1,2,5,6,5,7};
    assert(climbTheHill(slope) == 1);
    slope = {9,8,7,2,3,3};
    assert(climbTheHill(slope) == 1);
    slope = {9,8,9,8,9,8};
    assert(climbTheHill(slope) == 2);
    slope = {9,8,7,8,9};
    assert(climbTheHill(slope) == 2);
    slope = {5,2,3,5};
    assert(climbTheHill(slope) == 3);
    slope = {3,4,2,1,5,7};
    assert(climbTheHill(slope) == 4);
}

int main()
{
    test();
}