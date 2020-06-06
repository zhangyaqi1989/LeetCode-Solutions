class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = []
        for i, ch in enumerate(s):
            if ch == '(':
                stack.append(i)
            else:
                if stack and s[stack[-1]] == '(':
                    stack.pop()
                else:
                    stack.append(i)
        stack = [-1] + stack + [len(s)]
        return max(stack[i + 1] - stack[i] - 1 for i in range(len(stack) - 1))
