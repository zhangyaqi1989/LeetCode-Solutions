class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        ans = []
        carry = 0
        for v1, v2 in itertools.zip_longest(a[::-1], b[::-1], fillvalue='0'):
            carry, v = divmod(int(v1) + int(v2) + carry, 2)
            ans.append(v)
        if carry:
            ans.append(carry)
        return ''.join(map(str, ans))[::-1]