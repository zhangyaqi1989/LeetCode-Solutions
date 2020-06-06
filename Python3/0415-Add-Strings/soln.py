class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        carry = 0
        res, unit = 0, 1
        for c1, c2 in itertools.zip_longest(num1[::-1], num2[::-1], fillvalue='0'):
            carry, val = divmod(carry + int(c1) + int(c2), 10)
            res += unit * val
            unit *= 10
        return str(res + carry * unit)