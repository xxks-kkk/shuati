# Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
#
# For example,
# MovingAverage m = new MovingAverage(3);
# m.next(1) = 1
# m.next(10) = (1 + 10) / 2
# m.next(3) = (1 + 10 + 3) / 3
# m.next(5) = (10 + 3 + 5) / 3

import collections

class MovingAverage:
    def __init__(self, size):
        """
        Initialize your data structure here.
        :type size: int
        """
        self.queue = collections.deque()
        self.size = size
        self.sum = 0.0
        self.length = 0

    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        if len(self.queue) < self.size:
            self.queue.appendleft(val)
            self.sum += val
            self.length += 1
        else:
            tmp  = self.queue.pop()
            self.queue.appendleft(val)
            self.sum = self.sum - tmp + val
        return self.sum / self.length

class MovingAverage1:
    def __init__(self, size):
        """
        Initialize your data structure here.
        :type size: int
        """
        self.array = [0] * size
        self.size = size
        self.sum = 0.0
        self.idx = 0

    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        self.sum -= self.array[self.idx % self.size]
        self.array[self.idx % self.size] = val
        self.sum += val
        self.idx += 1
        return self.sum / min(self.idx, self.size)



# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)

if __name__ == "__main__":
    size = 3
    obj = MovingAverage(size)
    assert obj.next(1) == 1
    assert obj.next(10) == (1 + 10) / 2.0
    assert obj.next(3) == (1 + 10 + 3) / 3.0
    assert obj.next(5) == (10 + 3 + 5) / 3.0

    obj1 = MovingAverage1(size)
    assert obj1.next(1) == 1
    assert obj1.next(10) == (1 + 10) / 2.0
    assert obj1.next(3) == (1 + 10 + 3) / 3.0
    assert obj1.next(5) == (10 + 3 + 5) / 3.0