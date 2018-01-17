# Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
#
# For example,
# Given n = 3, your program should return all 5 unique BST's shown below.
#
#    1         3     3      2      1
#     \       /     /      / \      \
#      3     2     1      1   3      2
#     /     /       \                 \
#    2     1         2                 3

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def list2Tree(self, nums):
        for num in nums:
            self.root = self.insert(num, self.root)
        return self.root

    def insert(self, x, root):
        if not root:
            root = TreeNode(x)
        else:
            if x < root.val:
                root.left = self.insert(x, root.left)
            elif x > root.val:
                root.right = self.insert(x, root.right)
            # if x is in the tree already, we do nothing
        return root

    def printTree(self, root):
        def bst_print_dot_aux(root):
            if root:
                if root.left:
                    f.write("%d->%d;\n" % (root.val, root.left.val))
                    bst_print_dot_aux(root.left)
                if root.right:
                    f.write("%d->%d;\n" % (root.val, root.right.val))
                    bst_print_dot_aux(root.right)
        f = open("bst.dot", "w")
        f.write("digraph bst {\n")
        bst_print_dot_aux(root)
        f.write("}\n")
        f.close()

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

class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        def genTrees(start, end):
            list = []
            if start > end:
                list.append(None)
            for idx in range(start, end+1):
                leftList = genTrees(start, idx-1)
                rightList = genTrees(idx+1, end)
                for left_root in leftList:
                    for right_root in rightList:
                        root = TreeNode(idx)
                        root.left = left_root
                        root.right = right_root
                        list.append(root)
            return list
        if n == 0:
            return []
        return genTrees(1, n)


if __name__ == "__main__":
    bst = BST()
    # root = bst.list2Tree([1,2,3])
    # bst.printTree(root)
    # print(bst.printTree2(root))

    sol = Solution()
    list = sol.generateTrees(3)
    for root in list:
        print(bst.printTree2(root))
