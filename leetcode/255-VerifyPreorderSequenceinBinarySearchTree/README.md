## Solution explanation

Let me first present my failed attempt

```cpp
class Solution {
public:
    // assume bst is valid (preorder array is generated from a valid bst)
    bool verifyPreorder(vector<int>& preorder) {
        auto current = preorder.begin();
        auto prev = preorder.begin();
        bool endDecrease = false;
        bool endIncrease = false;
        bool traverseRight = false;
        if (preorder.size() > 1)
        {
            if(preorder[1] > preorder[0])
            {
                traverseRight = true;
            }
        }
        while(current != preorder.end())
        {
            if (!traverseRight)
            {
                if(!endDecrease && *current > *prev)
                {
                    endDecrease = true;
                }
                else if(endDecrease && *current < *prev) // else if is important
                {
                    return false;
                }
            }
            else
            {
                if(!endIncrease && *current < *prev)
                {
                    endIncrease = true;
                }
                else if(endIncrease && *current > *prev)
                {
                    return false;
                }
            }
            prev = current;
            ++current;
        }
        return true;
    }
};
```

The intuition for the solution is based on the following observation: let's take following bst as an example

```
    5
   / \
  2   6
 / \
 1  3
```

Pre-order traversal gives `5,2,1,3,6` and some incorrect traversal gives `5,2,6,1,3`. We can observe that
`5,2,1` is a decreasing sequence: we print left child’s value of current node all the way until we reached a leaf node.
Then `3` is greater than `1` and itself is a child of `2` and any number comes after (i.e. `6`) is greater than `3`.

My thought is to check whether the sequence of numbers are decreasing until a point (`1`) and then increasing afterwards.
If so, it is a preorder traversal and not otherwise. In addition, I distinguish between whether there is a left subtree
of the root. If not (i.e., `traverseRight == true`), then `preorder` is first increasing and then decreasing:

```
  1
   \
    3
   /
  2
```

The preorder gives `1,3,2`. However, my solution can easily fail if for example, the incorrect traversal gives `2,3,1`
of the same bst above. In addition, the trend of sequence can vary. For example,

```
     5
   /  \
  2    7
 / \  /
1   3 6
```

The preorder traversal gives `5,2,1,3,7,6`, which has the trend: decreasing, increasing, and then decreasing.

### Method 1: Using stack

This method is based on the observation we make about the preorder traversal:

we print left child’s value of current node all the way until we reached a leaf node (i.e. the number is decreasing),
and then we print the value of a node which is the right child of one of the nodes (denote $p$) that we already visited (i.e., `3` in
the first bst; we denote $rc$). We know a node is a right child of some node when we see the node's value is greater than the immediately
previous one (i.e., when sequence begin increase). Also, at that moment, we know: nodes'value in left subtree < $p$'s value < $rc$'s value.
Thus, $p$'s value becomes the lower bound for any upcoming nodes. Thus, whenever we see a upcoming node smaller than lower bound's value
(i.e. $p$'s value), we know it is not from a preorder traversal. Thus, our goal is to find lower bound, which is the same as
finding $p$'s value.

To translate this into code: looking for the trend of numbers, if it’s decreasing, it’s still traversing
the left child node all the way down, we push the value into stack. When we read a value greater than the last one,
we know the current value belongs to a right node (node $rc$) of one of the previous nodes (node $p$) we pushed to stack,
in other words, $p$ is the parent node of the current node $rc$. Due to the property of preorder traversal, $p$’s value
is pushed to stack before its left subtree nodes, so to find the parent node, we pop all the nodes in its left subtree,
and the last popped node whose value is smaller than $rc$ is $rc$’s parent $p$, whose value becomes the lower bound.
Then we keep reading the serialized array, in any case we see any value not greater than the lower bound, we return false.
Lower bound is updated whenever we read a right child node’s value.


- Time complexity: $O(n)$
- Space complexity: $O(h)$


### Method 2: In-place approach

We can reduce the space complexity to constant using the given `preorder` array. The idea is the same as M1 but we
directly use `preorder` as a stack. `i` works like the pointer pointing to the top of stack and we update the stack (i.e. `preorder`)
in the same fashion as M1.

- Time complexity: $O(n)$
- Space complexity: $O(1)$

## Reference

- https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/discuss/68185/C++-easy-to-understand-solution-with-thought-process-and-detailed-explanation
- https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/discuss/68142/Java-O(n)-and-O(1)-extra-space