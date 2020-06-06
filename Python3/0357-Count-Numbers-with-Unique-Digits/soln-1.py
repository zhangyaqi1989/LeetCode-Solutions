class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        elif n == 1:
            return 10
        else:
            choice = [9, 8, 7, 6, 5, 4, 3, 2, 1];
            n = min(n, 10)
            ans = 10
            cnt = 9
            for i in range(n - 1):
                cnt *= choice[i]
                ans += cnt
            return ans
