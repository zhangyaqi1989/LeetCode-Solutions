# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        depths = [collections.defaultdict(list) for _ in range(500)]
        self.mx = 0
        def helper(node, depth):
            if node:
                l = helper(node.left, depth + 1)
                r = helper(node.right, depth + 1)
                ans = max(l, r)
                self.mx = ans
                depths[depth][ans].append(node)
                return ans
            else:
                return depth - 1
        helper(root, 0)
        while True:
            depths.pop()
            if len(depths[-1][self.mx]) == 1:
                return depths[-1][self.mx][0]
        
