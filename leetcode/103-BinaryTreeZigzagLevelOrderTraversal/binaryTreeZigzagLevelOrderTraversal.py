 # [Source] 
 #          
 # https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 #          
 # [Problem Description]
 #          
 # Given a binary tree, return the zigzag level order traversal of its nodes'
 # values. (ie, from left to right, then right to left for the next level and
 # alternate between).
 # 
 # For example:
 # Given binary tree [3,9,20,null,null,15,7],
 # 
 # 3
 # / \
 # 9  20
 # /  \
 # 15   7
 # 
 # return its zigzag level order traversal as:
 # 
 # [
 # [3],
 # [20,9],
 # [15,7]
 # ]
 #          
 # [Comments]
 #          
 #          
 #          
 # [Companies]
 # Bloomberg


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        # Reference: http://algorithms.tutorialhorizon.com/level-order-traversal-in-zig-zag-pattern-or-print-in-spiral-pattern/
        evenLevel = False # Root level is counted as level 0
        queue = []
        res = []
        if not root:
            return []
        queue.append(root)
        while queue:
            levelNodes = len(queue)
            al = []
            while levelNodes > 0:
                n = queue.pop(0)
                al.append(n.val)
                if (n.left):
                    queue.append(n.left)
                if (n.right):
                    queue.append(n.right)
                levelNodes -= 1
            if evenLevel:
                al.reverse()
                res.append(al)
                evenLevel = False
            else:
                res.append(al)
                evenLevel = True
        return res


