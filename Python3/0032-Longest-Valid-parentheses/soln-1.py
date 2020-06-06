class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
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
        return max(b - a - 1 for a, b in zip(stack, stack[1:]))