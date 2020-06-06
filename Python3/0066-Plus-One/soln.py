class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1
        res = []
        digits = digits[::-1]
        for i, digit in enumerate(digits):
            carry, val = divmod(carry + digit, 10)
            res.append(val)
            if not carry:
                res.extend(digits[i+1:])
                return res[::-1]
        if carry:
            res.append(carry)
        return res[::-1]