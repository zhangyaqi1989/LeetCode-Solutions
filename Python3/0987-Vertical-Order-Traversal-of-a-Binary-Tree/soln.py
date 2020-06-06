# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def verticalTraversal(self, root: 'TreeNode') -> 'List[List[int]]':
        ans = collections.defaultdict(list)
        def traverse(node, x, y):
            if node:
                ans[x].append((y, node.val))
                traverse(node.left, x - 1, y + 1)
                traverse(node.right, x + 1, y + 1)
        traverse(root, 0, 0)
        ret = []
        for key in sorted(ans):
            lst = sorted(ans[key])
            ret.append([b for a, b in lst])
        return ret
