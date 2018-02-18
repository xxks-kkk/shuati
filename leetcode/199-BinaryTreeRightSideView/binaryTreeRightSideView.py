# Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
#
# For example:
# Given the following binary tree,
#    1            <---
#  /   \
# 2     3         <---
#  \     \
#   5     4       <---
# You should return [1, 3, 4].

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
                res.extend(path)
            return res

class Solution:
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []
        if root:
            queue = []
            queue.insert(0,root)
            while queue:
                numItemOnCurrLevel = len(queue)
                for i in range(numItemOnCurrLevel):
                    node = queue.pop()
                    if node.left:
                        queue.insert(0, node.left)
                    if node.right:
                        queue.insert(0, node.right)
                    if i == numItemOnCurrLevel - 1:
                        res.append(node.val)
        return res


if __name__ == "__main__":
    sol = Solution()
    bt = BT()

    root = bt.list2Tree([1,2,3,None,5,None,4])
    assert sol.rightSideView(root) == [1,3,4]
    root = bt.list2Tree([1,2,3,4])
    assert sol.rightSideView(root) == [1,3,4]