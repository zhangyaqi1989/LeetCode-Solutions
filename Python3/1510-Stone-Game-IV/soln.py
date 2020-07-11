class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = [-1] * (n + 1)
        def helper(left):
            if left <= 0:
                return False
            if dp[left] != -1:
                return dp[left]
            r = 1
            ans = False
            while r * r <= left:
                if not helper(left - r * r):
                    ans = True
                    break
                r += 1
            dp[left] = ans
            return ans
        return helper(n)
