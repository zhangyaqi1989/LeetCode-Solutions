class Solution:
    def parseTernary(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        stack = []
        for ch in reversed(expression):
            stack.append(ch)
            if stack[-2:-1] == ['?']:
                stack[-5:] = stack[-3 if stack[-1] == 'T' else -5]
        return stack[0]