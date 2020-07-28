# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maximumAverageSubtree(self, root: TreeNode) -> float:
        self.max_avg = -math.inf
        def postorder(node):
            if node is None:
                return 0.0, 0
            left_sum, left_cnt = postorder(node.left)
            right_sum, right_cnt = postorder(node.right)
            s = left_sum + right_sum + node.val
            cnt = left_cnt + right_cnt + 1
            self.max_avg = max(self.max_avg, s / cnt)
            return s, cnt
        postorder(root)
        return self.max_avg
