class Solution:
    def reachNumber(self, target):
        """
        :type target: int
        :rtype: int
        """
        # n^2 + n - 2 * target = 0
        target = abs(target)
        n = math.ceil((-1 + math.sqrt(1 + 8 * target)) / 2)
        summation = (1 + n) * n / 2;
        if summation == target:
            return n
        res = summation - target
        if res % 2 == 0:
            return n
        else:
            return n + (2 if n % 2 == 1 else 1)
