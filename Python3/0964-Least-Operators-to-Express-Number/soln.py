class Solution:
    def leastOpsExpressTarget(self, x, target):
        """
        :type x: int
        :type target: int
        :rtype: int
        """
        digits = []
        while target:
            digits.append(target % x)
            target //= x
        n = len(digits)
        pos = digits[0] * 2
        neg = (x - digits[0]) * 2
        for i in range(1, n):
             pos, neg = min(digits[i] * i + pos, digits[i] * i + i + neg), min((x - digits[i]) * i + pos, (x-digits[i]) * i + i + neg - 2 * i)
        return min(pos-1, n+neg-1)
