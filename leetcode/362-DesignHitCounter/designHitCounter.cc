/*************************************************************************
  > File Name:       designHitCounter.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/23/18
  > Description:
    
    Design a hit counter which counts the number of hits received in the past 5 minutes.

    Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls
    are being made to the system in chronological order (ie, the timestamp is monotonically increasing).
    You may assume that the earliest timestamp starts at 1.

    It is possible that several hits arrive roughly at the same time.

    Example:

    HitCounter counter = new HitCounter();

    // hit at timestamp 1.
    counter.hit(1);

    // hit at timestamp 2.
    counter.hit(2);

    // hit at timestamp 3.
    counter.hit(3);

    // get hits at timestamp 4, should return 3.
    counter.getHits(4);

    // hit at timestamp 300.
    counter.hit(300);

    // get hits at timestamp 300, should return 4.
    counter.getHits(300);

    // get hits at timestamp 301, should return 3.
    counter.getHits(301);
    Follow up:
    What if the number of hits per second could be very large? Does your design scale?
 ************************************************************************/

#include <cassert>
#include <vector>


class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {}

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int index = timestamp % 300;
        if (times[index] != timestamp)
        {
            times[index] = timestamp;
            hits[index] = 1;
        }
        else
        {
            hits[index] += 1;
        }
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int count = 0;
        for(int i = 0; i < 300; ++i)
        {
            if(timestamp - times[i] < 300)
            {
                count += hits[i];
            }
        }
        return count;
    }
private:
    int times[300] = {0};
    int hits[300] = {0};
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */

void test()
{
    HitCounter obj = HitCounter();
    obj.hit(1);
    obj.hit(2);
    obj.hit(3);
    assert(obj.getHits(4) == 3);
    obj.hit(300);
    assert(obj.getHits(300) == 4);
    assert(obj.getHits(301) == 3);
}

int main()
{
    test();
}