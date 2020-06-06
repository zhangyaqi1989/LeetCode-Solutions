class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        fibs = [1, 1]
        while fibs[-1] <= k:
            fibs.append(fibs[-1] + fibs[-2])
        cnt = 0
        while k:
            cnt += 1
            idx = bisect.bisect_left(fibs, k)
            if fibs[idx] == k:
                break
            else:
                k -= fibs[idx - 1]
        return cnt
