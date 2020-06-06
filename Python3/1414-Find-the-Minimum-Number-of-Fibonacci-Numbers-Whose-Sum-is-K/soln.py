class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        fibs = [1, 1]
        while fibs[-1] <= k:
            fibs.append(fibs[-1] + fibs[-2])
        def helper(num):
            idx = bisect.bisect_left(fibs, num)
            if fibs[idx] == num:
                return 1
            return 1 + helper(num - fibs[idx - 1])
        return helper(k)
