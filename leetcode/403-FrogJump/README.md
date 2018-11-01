## Solution explanation

In the DP Approach, we make use of a hashmap which contains key,value
pairs such that key refers to the position at which a stone is present 
and value is a set containing the jumpsize which can lead to 
the current stone position. We start by making a hashmap whose key are
all the positions at which a stone is present and the value 
are all empty except position 0 whose value contains 0. 
Then, we start traversing the elements(positions) of the given stone array 
in sequential order. For the currentPosition, for every possible jumpsize 
in the value set, we check if currentPosition + newjumpsize
exists in the map, where newjumpsize can be either jumpsize-1, 
jumpsize, jumpsize+1. If so, we append the corresponding value set 
with newjumpsize. We continue in the same manner. 
If at the end, the value set corresponding to the last position is non-empty, 
we conclude that reaching the end is possible, otherwise, it isn't.

## Reference

- https://leetcode.com/articles/frog-jump/