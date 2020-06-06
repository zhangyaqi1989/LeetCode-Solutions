class Solution:
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        rindex = {ch : i for i, ch in enumerate(s)}
        stack = []
        for i, ch in enumerate(s):
            if ch not in stack:
                while stack and ch < stack[-1] and i < rindex[stack[-1]]:
                    stack.pop()
                stack.append(ch)
        return ''.join(stack)