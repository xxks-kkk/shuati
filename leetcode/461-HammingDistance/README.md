## Solution explanation

We use Brian Kernighan's way to solve this problem. This solution is mentioned
in K&R Exercise 2-9.

```
In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in 
x. Explain why. Use this observation to write a faster version of bitcount.
```

Then the algorithm is 

```
1  Initialize count: = 0
2  If integer n is not zero
   (a) Do bitwise & with (n-1) and assign the value back to n
       n: = n&(n-1)
   (b) Increment count by 1
   (c) go to step 2
3  Else return Count
```

and our solution is 

```c
int hammingDistance(int x, int y) {
  unsigned int v;
  unsigned int c; // accumulates the total bits set in v
  v = x ^ y;
  for(c = 0; v; c++)
  {
    v &= v - 1; // clear the leastsignificant bit set
  }
  return c;
}
```

Here is an example

```
n =  9 (1001)
count = 0

Since 9 > 0, subtract by 1 and do bitwise & with (9-1)
n = 9&8  (1001 & 1000)
n = 8
count  = 1

Since 8 > 0, subtract by 1 and do bitwise & with (8-1)
n = 8&7  (1000 & 0111)
n = 0
count = 2

Since n = 0, return count which is 2 now.
```

This algorithm runs $O(\log n)$.

## Links

- [Bit Twiddling Hacks](http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan)
- [Count set bits in an integer](http://www.geeksforgeeks.org/count-set-bits-in-an-integer/)
