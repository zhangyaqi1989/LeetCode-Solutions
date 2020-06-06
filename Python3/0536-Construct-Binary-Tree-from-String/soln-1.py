# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def str2tree(self, s: str) -> TreeNode:
        if not s:
            return None
        self.i = 0
        return self.build(s)
        
    def build(self, s):
        start = self.i
        while self.i < len(s) and s[self.i] not in '()':
            self.i += 1
        val = int(s[start:self.i])
        root = TreeNode(val)
        if self.i < len(s) and s[self.i] == '(':
            self.i += 1
            root.left = self.build(s);
            self.i += 1
        if self.i < len(s) and s[self.i] == '(':
            self.i += 1
            root.right = self.build(s);
            self.i += 1
        return root
