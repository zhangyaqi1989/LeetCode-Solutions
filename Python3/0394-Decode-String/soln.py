class Solution:
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = [['', 0]]
        num = ''
        for ch in s:
            if ch.isdigit():
                num += ch
            elif ch.isalpha():
                stack[-1][0] += ch
            elif ch == '[':
                stack.append(['', int(num)])
                num = ''
            else:
                rep, n = stack.pop()
                stack[-1][0] += rep * n
        return stack[0][0]