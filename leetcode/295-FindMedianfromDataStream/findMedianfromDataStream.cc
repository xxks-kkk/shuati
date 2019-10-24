//    Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
//
//    For example,
//    [2,3,4], the median is 3
//
//    [2,3], the median is (2 + 3) / 2 = 2.5
//
//    Design a data structure that supports the following two operations:
//
//    void addNum(int num) - Add a integer number from the data stream to the data structure.
//    double findMedian() - Return the median of all elements so far.

#include <cassert>
#include <queue>

using namespace std;

class MedianFinder
{
public:
  /** initialize your data structure here. */
  MedianFinder()
  {
  }

  void
  addNum(int num)
  {
    // Add num to lo
    lo.push(num);
    // lo has one extra number, to make it still n elements,
    // we move the max element to hi
    hi.push(lo.top());
    lo.pop();
    // hi may have more elements (invariant: lo.size() >= hi.size() or lo has at least n elements)
    // we move the smallest element of hi to lo
    if (lo.size() < hi.size())
    {
      lo.push(hi.top());
      hi.pop();
    }
  }

  double
  findMedian()
  {
    if (lo.size() > hi.size())
    {
      // case: k = 2n + 1 (lo hold n+1 elements)
      return lo.top();
    }
    else
    {
      // case: k = 2n (lo and hi have n elements)
      return (lo.top() + hi.top()) * 0.5;
    }
  }

private:
  // heap used to store the smaller half of the numbers
  priority_queue<int, vector<int>, less<int>> lo; // max heap
  // heap used to store the larger half of the numbers
  priority_queue<int, vector<int>, greater<int>> hi; // min heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main()
{
  auto obj = new MedianFinder();
  obj->addNum(1);
  obj->addNum(2);
  assert(obj->findMedian() == 1.5);
  obj->addNum(3);
  assert(obj->findMedian() == 2);
}
