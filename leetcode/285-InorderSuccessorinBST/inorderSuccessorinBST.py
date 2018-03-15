# Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
#
# Note: If the given node has no in-order successor in the tree, return null.

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BST:
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

    def printTree2(self, root):
        # print the tree in the a list format that is the same as the leetcode's
        # 1
        #  \
        #   2      ->  ['1', 'null', '2', 'null', '3']
        #    \
        #     3
        res = []
        def printTree2_helper(res, root):
            if root:
                res.append(str(root.val))
                if root.left or root.right:
                    printTree2_helper(res, root.left)
                    printTree2_helper(res, root.right)
            else:
                res.append("null")
        printTree2_helper(res, root)
        return res

class Solution(object):
    def inorderSuccessor(self, root, p):
        """
        :type root: TreeNode
        :type p: TreeNode
        :rtype: TreeNode
        """
        succ = None
        while root:
            if p.val < root.val:
                succ = root
                root = root.left
            else: # p.val >= root.val
                root = root.right
        return succ

    def inorderPredecessor(self, root, p):
        """
        :type root: TreeNode
        :type p: TreeNode
        :rtype: TreeNode
        """
        predecessor = None
        while root:
            if p.val <= root.val:
                root = root.left
            else: # p.val > root.val
                predecessor = root
                root = root.right
        return predecessor


if __name__ == "__main__":
    sol = Solution()
    bt = BST()
    test1 = bt.list2Tree([2,1])
    assert sol.inorderSuccessor(test1, TreeNode(1)).val == 2
    test2 = bt.list2Tree([5,3,None,2,4])
    assert sol.inorderSuccessor(test2, TreeNode(4)).val == 5
    assert sol.inorderPredecessor(test2, TreeNode(4)).val == 3
    assert sol.inorderPredecessor(test2, TreeNode(3)).val == 2
