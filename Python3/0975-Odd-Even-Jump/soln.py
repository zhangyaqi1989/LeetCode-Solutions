from functools import lru_cache
class Solution:
    def oddEvenJumps(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        dp = [[-1, -1] for _ in range(n)] # [even, odd]
        lst = []
        for i in reversed(range(n)):
            idx = bisect.bisect_left(lst, [A[i], 0])
            if idx < len(lst) and lst[idx][0] == A[i]:
                dp[i] = [lst[idx][1], lst[idx][1]]
                lst[idx][1] = i
            else:
                dp[i][0] = lst[idx - 1][1] if idx > 0 else -1
                dp[i][1] = lst[idx][1] if idx < len(lst) else -1
                bisect.insort(lst, [A[i], i])
        @lru_cache(None)
        def jump(x, step):
            if x == n - 1:
                return True
            if x == -1:
                return False
            return jump(dp[x][step], 1 - step)
        return sum(jump(i, 1) for i in range(n))
