# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        def post_order(node, limit):
            if node is not None:
                node.left, l_mx = post_order(node.left, limit - node.val)
                node.right, r_mx = post_order(node.right, limit - node.val)
                mx = node.val + max(l_mx, r_mx)
                if mx >= limit:
                    return node, mx
                else:
                    return None, mx
            else:
                return None, 0
        ans, _ = post_order(root, limit)
        return ans
