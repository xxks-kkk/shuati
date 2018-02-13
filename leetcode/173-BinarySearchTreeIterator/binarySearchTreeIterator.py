# Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
#
# Calling next() will return the next smallest number in the BST.
#
# Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

# Definition for a  binary tree node
class TreeNode(object):
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

class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.stack = []
        while root:
            self.stack.append(root)
            root = root.left

    def hasNext(self):
        """
        :rtype: bool
        """
        return len(self.stack) != 0

    def next(self):
        """
        :rtype: int
        """
        node = self.stack.pop()
        res = node.val
        if node.right:
            node = node.right
            while node:
                self.stack.append(node)
                node = node.left
        return res

if __name__ == "__main__":
    bst = BST()
    root = bst.list2Tree([7,4,3,2])
    i, v = BSTIterator(root), []
    while i.hasNext():
        v.append(i.next())
    print(v)
