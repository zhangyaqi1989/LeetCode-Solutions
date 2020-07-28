# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:
        def search(node, val):
            cur = node
            while cur is not None:
                if cur.val == val:
                    return True
                elif cur.val < val:
                    cur = cur.right
                else:
                    cur = cur.left
            return False
        stack = []
        cur = root1
        while stack or cur is not None:
            while cur is not None:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            if search(root2, target - cur.val):
                return True
            cur = cur.right
        return False
