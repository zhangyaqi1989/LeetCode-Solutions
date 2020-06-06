class Solution:
    def nthMagicalNumber(self, N, A, B):
        """
        :type N: int
        :type A: int
        :type B: int
        :rtype: int
        """
        # 2 4 6 8 10
        LCM = A * B // math.gcd(A, B)
        mod = 10 ** 9 + 7
        l, r = min(A, B), min(A, B) * N
        while l < r:
            mid = (l + r) >> 1
            cnt = mid // A + mid // B - mid // LCM
            if cnt < N:
                l = mid + 1
            else:
                r = mid
        return l % mod
