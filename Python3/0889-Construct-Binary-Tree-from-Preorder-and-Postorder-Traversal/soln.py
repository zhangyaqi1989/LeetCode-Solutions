# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructFromPrePost(self, pre, post):
        """
        :type pre: List[int]
        :type post: List[int]
        :rtype: TreeNode
        """
        # pre and post
        if not pre:
            return None
        root = TreeNode(pre[0])
        s = set()
        for idx, (a, b) in enumerate(zip(pre[1:], post), 1):
            for c in (a, b):
                if c in s:
                    s.remove(c)
                else:
                    s.add(c)
            if len(s) == 0:
                root.left, root.right = self.constructFromPrePost(pre[1:1 + idx], post[:idx]), self.constructFromPrePost(pre[1 + idx:], post[idx:-1])
                break
        return root