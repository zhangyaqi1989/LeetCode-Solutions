# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
        lst = self.decode(root)
        lst.append(val)
        def build(lst):
            if not lst:
                return None
            mx = max(lst)
            idx = lst.index(mx)
            node = TreeNode(mx)
            node.left = build(lst[:idx])
            node.right = build(lst[idx+1:])
            return node
        return build(lst)
        
    def decode(self, root):
        if root:
            left = self.decode(root.left)
            right = self.decode(root.right)
            return left + [root.val] + right
        else:
            return []
