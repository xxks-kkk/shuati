## Solution Explanation

[Explanation from the first link in Reference section](https://leetcode.com/problems/multiply-strings/discuss/17605)
is very clear. Essentially, we get all the one-digit product and add them together. 
The key observation is actually:  `num1[i] * num2[j]` will be placed at indices `[i + j`, `i + j + 1]`,
which is demonstrated in the image below:

![demo](demo.jpg)

The whole algorithm is break down into two steps:

1. get all one-digit products
2. Sweep through the stored products and fix the digits with carry. For example,
for product `'123'*'456'`:

```
      1 2 3
x     4 5 6
----------------
        1 8
      1 2
    0 6
      1 5
    1 0
  0 5  
    1 2
  0 8
0 4
-----------------
0 5 6 0 8 8
```

One can see, for the hundreds place, the sum is 10, which has carry 1. The second step
of the algorithm above should fix the situation like this. Another note is that,
Since each one-digit product goes to the place based on the index of digit in each number,
we can perform the multiplication from left to right:

```python
for i in range(len(num1)):
    for j in range(len(num2)):
```


## Reference

- https://leetcode.com/problems/multiply-strings/discuss/17605
- https://leetcode.com/problems/multiply-strings/discuss/17605?page=2