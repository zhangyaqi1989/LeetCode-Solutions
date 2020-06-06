class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = [-1]
        max_len = 0
        for idx, ch in enumerate(s):
            if ch == '(':
                stack.append(idx)
            else:
                stack.pop()
                if not stack:
                    stack.append(idx)
                else:
                    max_len = max(max_len, idx - stack[-1])
        return max_len