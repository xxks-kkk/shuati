# Given inorder and postorder traversal of a tree, construct the binary tree.
#
# Note:
# You may assume that duplicates do not exist in the tree.

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
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        def buildTreeHelper(ileft, iright, pleft, pright):
            if ileft > iright or pleft > pright:
                return None
            root = TreeNode(postorder[pright])
            for i in range(ileft, iright+1):
                if inorder[i] == root.val:
                    break
            root.left = buildTreeHelper(ileft, i-1, pleft, pleft + i - 1 - ileft)
            root.right = buildTreeHelper(i+1, iright, pleft + i - ileft, pright - 1)
            return root
        return buildTreeHelper(0, len(inorder) - 1, 0, len(postorder) - 1)

    def buildTree2(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        def buildTreeHelper(ileft, iright, pleft, pright, hashMap):
            if ileft > iright or pleft > pright:
                return None
            root = TreeNode(postorder[pright])
            i = hashMap[root.val]
            root.left = buildTreeHelper(ileft, i-1, pleft, pleft + i - 1 - ileft, hashMap)
            root.right = buildTreeHelper(i+1, iright, pleft + i - ileft, pright - 1, hashMap)
            return root
        hashMap = {}
        for i in range(len(inorder)):
            hashMap[inorder[i]] = i
        return buildTreeHelper(0, len(inorder) - 1, 0, len(postorder) - 1, hashMap)


if __name__ == "__main__":
    bt = BT()
    root = bt.list2Tree([1,2,3,4,5])
    print(bt.printTree(root))

    sol = Solution()
    print(bt.printTree(sol.buildTree([4,2,5,1,3], [4,5,2,3,1])))
    print(bt.printTree(sol.buildTree2([4,2,5,1,3], [4,5,2,3,1])))