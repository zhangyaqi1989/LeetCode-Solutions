# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        queue = root and collections.deque([root])
        ans = []
        while queue:
            size = len(queue)
            max_val = float('-inf')
            for _ in range(size):
                node = queue.popleft()
                if node.val > max_val:
                    max_val = node.val
                queue.extend(filter(None, (node.left, node.right)))
            ans.append(max_val)
        return ans