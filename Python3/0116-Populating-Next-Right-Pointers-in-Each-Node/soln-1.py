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
        tail = dummy = TreeLinkNode(0)
        while root and root.left:
            tail.next = root.left
            tail = tail.next
            tail.next = root.right
            tail = tail.next
            root = root.next
            if not root:
                tail = dummy
                root = dummy.next