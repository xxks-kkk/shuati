## Solution explanation

由于数字在计算机是以二进制存储的，每位上都是0或1，如果我们把两个相同的数字异或 (XOR)，
0与0异或是0,1与1异或也是0，那么我们会得到0。根据这个特点，
我们把数组中所有的数字都异或起来，则每对相同的数字都会得0，
然后最后剩下来的数字就是那个只有1次的数字。

- If we take XOR of zero and some bit, it will return that bit

    - $a \oplus 0 = a$

- If we take XOR of two same bits, it will return 0

    - $a \oplus a =0$

- $a \oplus b \oplus a = a \oplus a \oplus b  = (a \oplus a) \oplus b = 0 \oplus b = b$

So we can XOR all bits together to find the unique number.

## Reference

- https://accu.org/index.php/journals/1915
- http://www.cnblogs.com/grandyang/p/4130577.html
- https://leetcode.com/problems/single-number/solution/
