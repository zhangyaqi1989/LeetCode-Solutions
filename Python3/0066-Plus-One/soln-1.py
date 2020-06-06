class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1
        i = len(digits) - 1
        while i >= 0 and carry:
            carry, val = divmod(digits[i] + carry, 10)
            digits[i] = val
            i -= 1
        return [1] + digits if carry else digits