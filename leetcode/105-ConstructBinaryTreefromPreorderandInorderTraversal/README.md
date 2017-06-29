## Solution explaination

The problem is

> Given preorder and inorder traversal of a tree, construct the binary tree.
> Note:
> You may assume that duplicates do not exist in the tree.

The tree doesn't have to be binary for the input.

Consider this input:

```
pre-order: [1,2,3,4]
in-order: [2,1,3,4]

     1            1
    /|\    ->    / \
   2 3 4        2   3
                     \
                      4
``` 

Then, we can build the binary tree as follows:

1. Since the first element of the `pre-order` traversal will always be the root
of the given tree. Then, we can use it as the root for our new tree. In our case,
`1` will be the root for our new tree.

2. We search the first element of the `pre-order` traversal in `in-order` traversal.
In this case, we search `1` in the in-order traversal

3. Split the `in-order` traversal by the element (i.e. `1`). In this case, we have,
`[2]`, `[3,4]`.

4. Split the rest of `pre-order` into two parts as large as the in-order traversal
corresponding part. In this case, pre-order is `[1,2,3,4]` and we split the rest
`[2,3,4]` into `[2]`, which corresponds to `[2]` in the in-order part and 
`[3,4]`, which corresponds to `[3,4]` in the in-order part.

5. Use `pre-order: [2]` and `in-order: [2]` to add the left subtree.

6. Use `pre-order: [3,4]` and `in-order: [3,4]` to add the right subtree.

For another example,

consider the input

```
pre-order: [1,2,4,5,3,6]
in-order: [4,2,5,1,6,3]

     1              1
    / \            / \
   2   3   ->     2   3
  / \  /         / \  /
 4  5 6         4  5 6
```

1. Use the firs element of `pre-order`, the `1` as root

2. Search it in `in-order`

3. Split `in-order` by it, here into `[4,2,5]` and `[6,3]`.

4. Split the rest of `pre-order` into two parts as large as the `in-order` parts, 
here into `[2, 4, 5]` and `[3, 6]`.

5. Use `pre-order = [2, 4, 5]` and `in-order = [4, 2, 5]` to add the left subtree.
                                                                           
6. Use `pre-order =[3, 6]` and `in-order = [6, 3]` to add the right subtree.

The algorithm is implemented below:

```c
struct TreeNode* buildTreeHelper(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd);

struct TreeNode* buildTree(int* preorder,
                           int preorderSize,
                           int* inorder,
                           int inorderSize)
{
  return buildTreeHelper(preorder, 0, preorderSize - 1, inorder, 0, inorderSize-1);
}

struct TreeNode* buildTreeHelper(int* preorder,
                                 int preStart,
                                 int preEnd,
                                 int* inorder,
                                 int inStart,
                                 int inEnd)
{
  if (preStart > preEnd || inStart > inEnd)
    return NULL;
  struct TreeNode* root = malloc(sizeof(struct TreeNode));
  root->val = preorder[preStart];
  root->left = root->right = NULL;
  int inIndex = 0; // Index of the current root in int* inorder
  int i;
  for(i = inStart; i <= inEnd; i++)
  {
    if (inorder[i] == root->val)
    {
      inIndex = i;
      break;
    }
  }
  root->left = buildTreeHelper(preorder, preStart+1, preStart + inIndex - inStart, inorder, inStart, inIndex-1);
  root->right = buildTreeHelper(preorder, preStart + inIndex - inStart + 1, preEnd, inorder, inIndex+1, inEnd);
  return root;
}
```

One remarks for the above implementation is that we don't actually do the split by creating two new arrays as suggested
by step 4. Instead, we split by telling the recursive calls where each part of the array start and end. 

The running time for the algorithm depends on the structure of the given tree:

-  If we assume that the constructed binary tree is always balanced, 
then we can guarantee the run time complexity to be $O(N \log N)$,
where $N$ is the number of nodes. 

-  If the tree is skewed to the left/right, then the complexity is $O(N^2)$.
(i.e. `pre-order: [1,2,3,4]; in-order: [4,3,2,1]`)

A more efficient way is to eliminate the search by using an efficient 
look-up mechanism such as hash table. 
By hashing an element’s value to its corresponding index in the 
inorder sequence, we can do look-ups in constant time. 
Now, we need only $O(N)$ time to construct the tree, 
which theoretically is the most efficient way.

The map can be built as follows:

```c
const int MAX = 256;
struct TreeNode* buildTreeHelper(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd, int* lookup, int offset);
int* mapIndex(int* inorder, int inorderSize);

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
int *lookup = mapIndex(inorder, inorderSize);
struct TreeNode* root = buildTreeHelper(preorder, 0, preorderSize - 1, inorder, 0, inorderSize-1, lookup, 0);
free(lookup);
return root;
}

// a fast lookup for inorder's element -> index
// binary tree's element must be in the range of [0, MAX-1]
int* mapIndex(int* inorder, int inorderSize)
{
  int* lookup = calloc(sizeof(int), MAX);
  int i;
  for(i = 0; i < inorderSize; i++)
  {
    assert(0 <= inorder[i] && inorder[i] <= MAX - 1);
    lookup[inorder[i]] = i;
  }
  return lookup;
}

struct TreeNode* buildTreeHelper(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd, int* lookup, int offset)
{
  if (preStart > preEnd || inStart > inEnd)
    return NULL;
  struct TreeNode* root = malloc(sizeof(struct TreeNode));
  root->val = preorder[preStart];
  root->left = root->right = NULL;
  int inIndex = 0; // Index of the current root in int* inorder
  inIndex = lookup[root->val] - offset;
  root->left = buildTreeHelper(preorder, preStart+1, preStart + inIndex - inStart, inorder, inStart, inIndex-1, lookup, offset);
  root->right = buildTreeHelper(preorder, preStart + inIndex - inStart + 1, preEnd, inorder, inIndex+1, inEnd, lookup, offset+inIndex+1);
  return root;
}
```

## Reference

- [Leetcode solution: Simple O(n) without map](https://discuss.leetcode.com/topic/16221/simple-o-n-without-map)
- [Leetcode solution: My Accepted Java Solution](https://discuss.leetcode.com/topic/3695/my-accepted-java-solution)
- [Leetcode article on this problem](http://web.archive.org/web/20150322225832/http://articles.leetcode.com/2011/04/construct-binary-tree-from-inorder-and-preorder-postorder-traversal.html)
