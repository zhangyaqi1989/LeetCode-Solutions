# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        self.cnt = 0
        def postorder(node):
            counter = [0] * 11
            if node is None:
                return counter
            left = postorder(node.left)
            right = postorder(node.right)
            if node.left is None and node.right is None:
                counter[0] += 1
                return counter
            else:
                for i in range(1, distance):
                    for j in range(1, distance - i + 1):
                        self.cnt += left[i - 1] * right[j - 1]
            for i in range(10):
                counter[i + 1] += left[i] + right[i]
            return counter
        postorder(root)
        return self.cnt
