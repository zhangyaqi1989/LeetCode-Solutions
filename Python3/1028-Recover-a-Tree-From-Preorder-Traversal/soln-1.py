# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        lo = 0
        stack = []
        for match in re.finditer(r'[0-9]+', S):
            # print(match.start() - lo, S[match.start():match.end()])
            depth = match.start() - lo
            val = int(S[match.start():match.end()])
            lo = match.end()
            node = TreeNode(val)
            while len(stack) > depth:
                stack.pop()
            if stack:
                if stack[-1].left is None:
                    stack[-1].left = node
                else:
                    stack[-1].right = node
            stack.append(node)
        return stack[0]
