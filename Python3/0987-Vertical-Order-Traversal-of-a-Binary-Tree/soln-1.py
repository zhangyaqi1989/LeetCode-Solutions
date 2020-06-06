# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def verticalTraversal(self, root: 'TreeNode') -> 'List[List[int]]':
        queue = collections.deque([(root, 0, 0)])
        d = collections.defaultdict(list)
        while queue:
            node, x, y = queue.popleft()
            d[x].append((y, node.val))
            if node.left:
                queue.append((node.left, x - 1, y + 1))
            if node.right:
                queue.append((node.right, x + 1, y + 1))
        ans = []
        for key in sorted(d):
            lst = sorted(d[key])
            ans.append([b for a, b in lst])
        return ans
