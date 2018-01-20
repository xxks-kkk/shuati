# Given a binary tree
#
#     struct TreeLinkNode {
#       TreeLinkNode *left;
#       TreeLinkNode *right;
#       TreeLinkNode *next;
#     }
# Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
#
# Initially, all next pointers are set to NULL.
#
# Note:
#
# You may only use constant extra space.
# You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
# For example,
# Given the following perfect binary tree,
#          1
#        /  \
#       2    3
#      / \  / \
#     4  5  6  7
# After calling your function, the tree should look like:
#          1 -> NULL
#        /  \
#       2 -> 3 -> NULL
#      / \  / \
#     4->5->6->7 -> NULL


# Definition for binary tree with next pointer.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None

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
                    if i == levelLength - 1:
                        path.append("#")
                res.append(path)
            return res

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if root:
            queue = []
            queue.insert(0, root)
            while queue:
                levelLength = len(queue)
                for i in range(levelLength):
                    node = queue.pop()
                    if node.left:
                        queue.insert(0, node.left)
                    if node.right:
                        queue.insert(0, node.right)
                    if i != levelLength - 1:
                        next_node = queue[-1]
                        node.next = next_node
                    else:
                        node.next = None

    def connect2(self, root):
        level_start = root
        while level_start:
            curr = level_start
            while curr:
                if curr.left:
                    curr.left.next = curr.right
                if curr.right and curr.next:
                    curr.right.next = curr.next.left
                curr = curr.next
            level_start = level_start.left


if __name__ == "__main__":
    bt = BT()
    sol = Solution()

    root = bt.list2Tree([0,1,2,3,4,5,6])
    sol.connect(root)
    print(bt.printTree(root))

    root = bt.list2Tree([0,1,2,3,4,5,6])
    sol.connect2(root)
    print(bt.printTree(root))