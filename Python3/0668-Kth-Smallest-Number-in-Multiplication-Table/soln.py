class Solution:
    def findKthNumber(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        def count_less_than(num):
            return sum(min(num // i, n) for i in range(1, m + 1))
        l, r = 1, m * n
        while l < r:
            mid = (l + r) >> 1
            cnt = count_less_than(mid)
            if cnt >= k:
                r = mid
            else:
                l = mid + 1
        return l