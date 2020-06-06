class Solution:
    def consecutiveNumbersSum(self, N):
        """
        :type N: int
        :rtype: int
        """
        # count odd factors
        res = 1
        i = 3
        while N % 2 == 0:
            N /= 2
        while i * i <= N:
            count = 0
            while N % i == 0:
                N /= i
                count += 1
            res *= (count + 1)
            i += 2
        return res if N == 1 else res * 2