# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        def postorder(node):
            if node is not None:
                lh, l_lca = postorder(node.left)
                rh, r_lca = postorder(node.right)
                if lh > rh:
                    return lh + 1, l_lca
                elif rh > lh:
                    return rh + 1, r_lca
                else:
                    return lh + 1, node
            else:
                return 0, None
        return postorder(root)[1]
        
