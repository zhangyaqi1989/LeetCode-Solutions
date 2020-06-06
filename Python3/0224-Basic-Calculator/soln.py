class Solution:
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        n, sign, res, stack, i = len(s), 1, 0, [], 0
        while i < n:
            if s[i] == ' ':
                i += 1
                continue
            elif s[i].isdigit():
                num = int(s[i])
                while i + 1 < n and s[i + 1].isdigit():
                    num = num * 10 + int(s[i + 1])
                    i += 1
                res += num * sign
            elif s[i] == '+':
                sign = 1
            elif s[i] == '-':
                sign = -1
            elif s[i] == '(':
                stack.append(res)
                stack.append(sign)
                res = 0
                sign = 1
            elif s[i] == ')':
                res = res * stack.pop() + stack.pop()
            i += 1
        return res