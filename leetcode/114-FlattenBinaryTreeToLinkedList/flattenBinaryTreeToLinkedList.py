# Given a binary tree, flatten it to a linked list in-place.
#
# For example,
# Given
#
#          1
#         / \
#        2   5
#       / \   \
#      3   4   6
# The flattened tree should look like:
#    1
#     \
#      2
#       \
#        3
#         \
#          4
#           \
#            5
#             \
#              6

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BT:
    def __init__(self):
        self.root = None

    def list2Tree(self, nums):
        if nums:
            queue = []
            root = TreeNode(nums[0])
            queue.insert(0, root)
            i = 1
            while queue and i < len(nums):
                node = queue.pop()
                if node:
                    if nums[i]:
                        left = TreeNode(nums[i])
                        node.left = left
                        queue.insert(0, left)
                    else:
                        node.left = None
                    i += 1
                    if i < len(nums):
                        if nums[i]:
                            right = TreeNode(nums[i])
                            node.right = right
                            queue.insert(0, right)
                        else:
                            node.right = None
                        i += 1
            return root

    def printTree(self, root):
        if root:
            queue = []
            res = []
            queue.insert(0, root)
            while queue:
                path = []
                levelLength = len(queue)
                for i in range(levelLength):
                    node = queue.pop()
                    path.append(node.val)
                    if node.left:
                        queue.insert(0, node.left)
                    if node.right:
                        queue.insert(0, node.right)
                res.append(path)
            return res

class Solution:
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        if not root:
            return
        else:
            tmp = root.right
            self.flatten(tmp)
            self.flatten(root.left)
            root.right = root.left
            root.left = None
            curr = root
            while curr.right:
                curr = curr.right
            curr.right = tmp

if __name__ == "__main__":
    bt = BT()
    root = bt.list2Tree([1,2,5,3,4,None,6])
    print(bt.printTree(root))

    sol = Solution()
    sol.flatten(root)
    print(bt.printTree(root))

    root = bt.list2Tree([1,2])
    sol.flatten(root)
    print(bt.printTree(root))

