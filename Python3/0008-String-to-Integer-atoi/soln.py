class Solution:
    def myAtoi(self, string):
        """
        :type string: str
        :rtype: int
        """
        # 1. leading whitespace
        # 2. optional plus or minus sign
        # 3. leading digits
        # 4. overflow
        string = string.lstrip()
        if not string: return 0
        start = 0
        sign = +1
        if string[0] in ('-', '+'):
            start = 1
            if string[0] == '-': sign = -1
        end = start
        while end < len(string):
            if not string[end].isdigit():
                break
            end += 1
        if end == start: return 0
        ans = sign * int(string[start:end])
        return min(max(ans, -2**31), 2**31 - 1)