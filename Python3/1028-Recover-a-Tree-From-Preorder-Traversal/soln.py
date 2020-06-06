# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        lo = 0
        n = len(S)
        root = None
        pre = -1
        stack = []
        while lo < n:
            depth = 0
            while lo < n and S[lo] == '-':
                lo += 1
                depth += 1
            val = 0
            while lo < n and S[lo].isdigit():
                val = val * 10 + int(S[lo])
                lo += 1
            node = TreeNode(val)
            if root is None:
                root = node
            if depth > pre:
                if stack:
                    stack[-1][0].left = node
            elif depth == pre:
                stack[-2][0].right = node
            else:
                while stack and stack[-1][1] >= depth:
                    stack.pop()
                stack[-1][0].right = node
            stack.append((node, depth))
            pre = depth
        return root
