# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def boundaryOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        lefts = [root]
        cur = root.left
        while cur:
            lefts.append(cur)
            cur = cur.left or cur.right
        rights = [root]
        cur = root.right
        while cur:
            rights.append(cur)
            cur = cur.right or cur.left
        leaves = []
        stack = [root]
        while stack:
            node = stack.pop()
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
            if node.left is None and node.right is None:
                leaves.append(node)
        ans = []
        seen = set()
        for node in itertools.chain(lefts, leaves, rights[::-1]):
            if node not in seen:
                ans.append(node.val)
                seen.add(node)
        return ans
