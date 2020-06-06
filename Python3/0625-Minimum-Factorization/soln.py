class Solution:
    def smallestFactorization(self, a):
        """
        :type a: int
        :rtype: int
        """
        if a == 1:
            return 1
        factors = []
        while a > 1:
            for b in range(9, 1, -1):
                if a % b == 0:
                    factors.append(b)
                    a //= b
                    break
            else:
                return 0
        ans = int(''.join(map(str, factors[::-1])))
        return ans if ans < 2 ** 31 else 0
