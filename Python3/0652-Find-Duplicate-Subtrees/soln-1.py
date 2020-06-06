# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        subs = collections.defaultdict(list) # map subtree to root
        def helper(node):
            if node is None:
                return ""
            left = helper(node.left)
            right = helper(node.right)
            ans = '^{}-{}-{}$'.format(node.val, left, right)
            subs[ans].append(node)
            return ans
        helper(root)
        return [value[0] for value in subs.values() if len(value) > 1]
