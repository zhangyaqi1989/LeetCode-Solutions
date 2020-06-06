# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def maxAncestorDiff(self, root: TreeNode) -> int:
        def postorder(node):
            if node:
                l_mn, l_mx = postorder(node.left)
                r_mn, r_mx = postorder(node.right)
                self.ans = max(self.ans, node.val - min(l_mn, r_mn), max(l_mx, r_mx) - node.val)
                return min(l_mn, r_mn, node.val), max(l_mx, r_mx, node.val)
            else:
                return math.inf, -math.inf
        self.ans = 0
        postorder(root)
        return self.ans
        
