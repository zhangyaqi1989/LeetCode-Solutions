"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    def treeToDoublyList(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if root is None:
            return root
        head = None
        pre = None
        cur, stack = root, []
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            node = stack.pop()
            if head is None:
                head = node
            if pre is not None:
                pre.right = node
                node.left = pre
            pre = node
            cur = node.right
        pre.right = head
        head.left = pre
        return head
