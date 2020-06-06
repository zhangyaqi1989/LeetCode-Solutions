class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for ch in s:
            if not stack or ch in ('(', '[', '{'):
                stack.append(ch)
            else:
                if stack.pop() + ch not in ('()', '[]', '{}'):
                    return False
        return not stack