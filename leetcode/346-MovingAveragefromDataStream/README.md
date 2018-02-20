## Solution explanation

### Understanding question

[Moving average](https://en.wikipedia.org/wiki/Moving_average) is a calculation to analyze data points by 
creating series of averages of different subsets of the full data set:

    Given a series of numbers and a fixed subset size, the first element of the moving average is obtained by 
    taking the average of the initial fixed subset of the number series. Then the subset is modified by 
    "shifting forward"; that is, excluding the first number of the series and including the next value in the subset.
    
Now, let's try to understand the question example:

```
MovingAverage m = new MovingAverage(3);  # windows size = 3 ("subset size" in wikipedia)
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
```

The example specifies a window size of `3` and then we have the window to slide over
a sequence of numbers `1,10,3,5`. First number is `1` and since the window size is `3`,
the moving average is `1` (imagine window size represents a bag that can only contain 3 items.).
Next number is `10`. Since window size is `3` and we have covered only 2 numbers so far,
then, the moving average is `(1+10)/2`. Next number is `3` and we have three numbers covered by
our window. Thus, moving average is `(1+10+3)/3`. Finally, the number is `5` and since our window
size is `3` and we need to throw out the oldest number, which is `1` and our average becomes
`(10+3+5)/3`.

### Solution 1: queue [Accepted]

The idea is to keep the sum so far and update the sum just by replacing the oldest number with the new entry.
Just to keep track of the number of elements in queue and sum we have so far, we can achieve $O(1)$ time
complexity.


### Solution 2: ring array [Accepted]

We can completely get rid of the queue and use a fixed length array. We can use `self.idx`
to keep track of how many numbers we have seen so far and use it to calculate
which value will be replaced `self.idx % self.size`. Be careful about when to increment `self.idx`.
If we increment it at very beginning, we eseentially only use `size-1` slots in array not whole
`size` slots.

## Reference
    
- https://leetcode.com/problems/moving-average-from-data-stream/discuss/81489/Simple-Python-solution-based-on-Circular-Array-real-O(1)-time-next()
- http://interviewsource.blogspot.com/2016/09/moving-average.html?q=moving+average (more complex setup)