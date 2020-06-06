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
    def connect(self, node):
        tail = dummy = TreeLinkNode(0)
        while node:
            tail.next = node.left
            if tail.next:
                tail = tail.next
            tail.next = node.right
            if tail.next:
                tail = tail.next
            node = node.next
            if not node:
                tail = dummy
                node = dummy.next