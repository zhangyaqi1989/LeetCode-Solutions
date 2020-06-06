class Solution:
    def myAtoi(self, string):
        """
        :type string: str
        :rtype: int
        """
        ZERO = 0
        string = string.lstrip(' ')
        if not string: return ZERO
        start, sign = (1, int(string[0] + '1')) if string[0] in ('+', '-') else (0, +1)
        end = start
        while end < len(string) and string[end].isdigit():
            end += 1
        if start == end: return ZERO
        num = sign * int(string[start:end])
        return min(2**31 - 1, max(num, -2**31))