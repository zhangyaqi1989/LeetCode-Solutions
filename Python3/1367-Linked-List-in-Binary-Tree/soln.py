# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def helper(cur: ListNode, node: TreeNode) -> bool:
    if cur is None:
        return True
    if node is None:
        return False
    return cur.val == node.val and (helper(cur.next, node.left) or helper(cur.next, node.right))

class Solution:
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        if root is None:
            return head is None
        return helper(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
