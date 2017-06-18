Take 5 as an example. The binary representation of 5 is 101 
(no leading zero bits), and its complement is 010. So you need to output 2.

## Failure attempts

The idea to solve this problem may look straightforward:

1. We can directly flip the bits

```
~ 101   <---- "5"
-------
  010   <---- "2"
```

This solution doesn't work because our number used 2's complement representation.
If we do direct filpping, the most significant will be 1, which gives us
`1010`, which is -6.

```
~ 0101
-------
  1010
```

2. We can use masking operations

```
~ 101   <---- "5"
-------
  010
& 111
-------
  010   <---- "2"
```

This will make us think the solution should be

```c
int findComplement(int num) {
    int mask = ~0;
    return mask & ~num;
}
```

Again, this solution doesn't take 2's complement representation into the consideration.
What really happens is 

```
~ 0101   <---- "5"
-------
  1010
& 1111
-------
  1010   <---- "-6"
```

## Solution explanation

What we really want is the following:

```
~ 0101   <---- "5"
-------
  1010
& 0111 
-------
  0010   <---- "2"
```

The key point is that we need to be careful with the most significant bit of our mask:
we want it to be `0` instead of `1`. 
How do we get `0111` is the key to solve this problem. Here is the process
to get this mask: 

```
~ 0111
-------
>>1000
-------
>>1100
-------
>>1110
-------
  1111
```

In other words, we can let `1111` repeatedly shift to the right (`<<`) until
we get to `1000`, and then we do 1's complement to get `0111`.

```
<< 1111
-------
<< 1110
-------
<< 1100
-------
<< 1000
~  1000
-------
   0111
```

Now, the only question left is to know how many times should we do right shift
operation (``<<``). Observe that `1000` is `1` on the most significant bit 
and `0` for the rest of bits. In addition, our input number is positive, which
means `0` on the most significant bit. Everytime after the right shift, we do
`&` with our input number and check if it is `0`: `0` can only happen when
our right shift result has leading bit `1` and the rest bits `0`. Once 
it is `0`, then we know we are done with right shift.

```
 0101 <---- "5" (input number)
&1000 
-------
 0000 
```

Put every piece together and we have our solution:

```c
int findComplement(int num) {
    unsigned mask = ~0;
    while (num & mask) mask <<= 1;
    return ~mask & ~num;
}
```
