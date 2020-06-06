# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if not root:
            return
        self.link(root.left, root.right)
        
    def link(self, left, right):
        if not left or not right:
            return
        left.next = right
        self.link(left.left, left.right)
        self.link(right.left, right.right)
        self.link(left.right, right.left)