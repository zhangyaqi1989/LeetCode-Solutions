class Solution:
    def canIWin(self, mx: int, target: int) -> bool:
        if target <= mx:
            return True
        if (1 + mx) * mx // 2 < target:
            return False
        memo = {}
        def helper(target, state, mx):
            if state in memo:
                return memo[state]
            ans = 2
            if target > 0:
                for i in range(1, mx + 1):
                    if (state & (1 << i)) == 0 and helper(target - i, state | (1 << i), mx) == 2:
                        ans = 1
                        break
            memo[state] = ans
            return ans
        return helper(target, 0, mx) == 1
