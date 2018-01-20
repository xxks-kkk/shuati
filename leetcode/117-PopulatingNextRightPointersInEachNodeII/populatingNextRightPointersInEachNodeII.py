# Follow up for problem "Populating Next Right Pointers in Each Node".
#
# What if the given tree could be any binary tree? Would your previous solution still work?
#
# Note:
#
# You may only use constant extra space.
# For example,
# Given the following binary tree,
#          1
#        /  \
#       2    3
#      / \    \
#     4   5    7
# After calling your function, the tree should look like:
#          1 -> NULL
#        /  \
#       2 -> 3 -> NULL
#      / \    \
#     4-> 5 -> 7 -> NULL

# Definition for binary tree with next pointer.
class TreeLinkNode:
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
            root = TreeLinkNode(nums[0])
            queue.insert(0, root)
            i = 1
            while queue and i < len(nums):
                node = queue.pop()
                if node:
                    if nums[i]:
                        left = TreeLinkNode(nums[i])
                        node.left = left
                        queue.insert(0, left)
                    else:
                        node.left = None
                    i += 1
                    if i < len(nums):
                        if nums[i]:
                            right = TreeLinkNode(nums[i])
                            node.right = right
                            queue.insert(0, right)
                        else:
                            node.right = None
                        i += 1
            return root

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if root:
            level_start = root
            while level_start:
                curr = level_start
                while curr:
                    if curr.left and curr.right:
                        curr.left.next = curr.right
                    if curr.left and not curr.right:
                        if not curr.next:
                            curr.left.next = None
                        else:
                            tmp = curr.next
                            left = right = None
                            while tmp:
                                if tmp.left:
                                    left = tmp.left
                                    break
                                elif tmp.right:
                                    right = tmp.right
                                    break
                                tmp = tmp.next
                            curr.left.next = left if left else right
                    if curr.right and curr.next:
                        tmp = curr.next
                        left = right = None
                        while tmp:
                            if tmp.left:
                                left = tmp.left
                                break
                            elif tmp.right:
                                right = tmp.right
                                break
                            tmp = tmp.next
                        curr.right.next = left if left else right
                    curr = curr.next
                while level_start:
                    if level_start.left:
                        level_start = level_start.left
                        break
                    elif level_start.right:
                        level_start = level_start.right
                        break
                    else:
                        level_start = level_start.next

    # @param root, a tree link node
    # @return nothing
    def connect2(self, root):
        while root:
            dummy = TreeLinkNode(0)
            curr = dummy
            dummy.next = None
            while root:
                if root.left:
                    curr.next = root.left
                    curr = curr.next
                if root.right:
                    curr.next = root.right
                    curr = curr.next
                root = root.next
            root = dummy.next


if __name__ == "__main__":
    bt = BT()
    sol = Solution()

    root = bt.list2Tree([0,2,4,1,None,3,-1,5,1,None,6,None,8])
    sol.connect(root)

    root = bt.list2Tree([0,2,4,1,None,3,-1,5,1,None,6,None,8])
    sol.connect2(root)