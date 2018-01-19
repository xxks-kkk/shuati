# Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
#
# For example:
# Given the below binary tree and sum = 22,
#               5
#              / \
#             4   8
#            /   / \
#           11  13  4
#          /  \    / \
#         7    2  5   1
# return
# [
#    [5,4,11,2],
#    [5,8,4,5]
# ]

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
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        res = []
        def dfs(sum, root, path, res):
            if root:
                if not root.left and not root.right and sum != root.val:
                    return
                if not root.left and not root.right and sum == root.val:
                    res.append(path + [root.val])
                    return
                dfs(sum - root.val, root.left, path + [root.val], res)
                dfs(sum - root.val, root.right, path + [root.val], res)
        dfs(sum, root, [], res)
        return res


if __name__ == "__main__":
    bt = BT()
    sol = Solution()
    root = bt.list2Tree([1,2])
    print(sol.pathSum(root, 1))
    root = bt.list2Tree([5,4,8,11, None, 13, 4, 7, 2, None, None, 5, 1])
    print(sol.pathSum(root, 22))