//    Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
//    find the minimum number of conference rooms required.
//
//    Example 1:
//
//    Input: [[0, 30],[5, 10],[15, 20]]
//    Output: 2
//    Example 2:
//
//    Input: [[7,10],[2,4]]
//    Output: 1

#include <vector>
#include <cassert>
#include <functional>
#include <iostream>
#include <queue>

using namespace std;

// Definition for an interval.
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
    // Sol1: using priority queue
    int
    minMeetingRooms(vector<Interval> &intervals)
    {
        if (intervals.empty())
        {
            return 0;
        }
        typedef function<bool(Interval, Interval)> Comparator;
        Comparator comp = [](Interval item1, Interval item2) -> bool
        {
            // C++: ascending order using < (by default)
            //      descending order using >
            return item1.start < item2.start;
        };
        sort(intervals.begin(), intervals.end(), comp);
        // C++: min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push((*intervals.begin()).end);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (pq.top() <= intervals[i].start)
            {
                pq.pop();
                pq.push(intervals[i].end);
            }
            else
            {
                pq.push(intervals[i].end);
            }
        }
        return pq.size();
    }

    // Sol2: using two pointers
    int
    minMeetingRooms2(vector<Interval> &intervals)
    {
        vector<int> start;
        vector<int> end;
        for(auto& interval: intervals)
        {
            start.push_back(interval.start);
            end.push_back(interval.end);
        }
        // ascending order
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int rooms = 0;
        int end_ptr = 0;
        for(int start_ptr = 0; start_ptr < start.size(); )
        {
            if (start[start_ptr] >= end[end_ptr])
            {
                // someone finish the meeting, free one meeting room
                rooms--;
                // we move to the next end time of the meeting
                end_ptr++;
            }
            // allocate a new room
            rooms++;
            // process the next meeting
            start_ptr++;
        }
        return rooms;
    }
};

using ptr2minMeetingRooms = int (Solution::*)(vector<Interval> &intervals);

void
test(ptr2minMeetingRooms pfcn)
{
    Solution sol;
    vector<Interval> intervals = {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
    assert((sol.*pfcn)(intervals) == 2);

    intervals = {Interval(7, 10), Interval(2, 4)};
    assert((sol.*pfcn)(intervals) == 1);

    intervals = {Interval(6,15), Interval(13,20), Interval(6,17)};
    assert((sol.*pfcn)(intervals) == 3);
}

int
main()
{
    ptr2minMeetingRooms pfcn = &Solution::minMeetingRooms;
    test(pfcn);

    pfcn = &Solution::minMeetingRooms2;
    test(pfcn);
}

