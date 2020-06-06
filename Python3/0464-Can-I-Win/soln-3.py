class Solution:
    def canIWin(self, mx: int, target: int) -> bool:
        if (1 + mx) * mx // 2 < target:
            return False
        if target == 0:
            return True
        memo = [0] * (1 << mx + 1)
        def helper(target, state, mx):
            if memo[state] != 0:
                return memo[state]
            if target <= 0:
                memo[state] = 2
                return 2
            else:
                for i in range(1, mx + 1):
                    if state & (1 << i) == 0:
                        if helper(target - i, state | (1 << i), mx) == 2:
                            memo[state] = 1
                            return 1
                memo[state] = 2
                return 2
        return helper(target, 0, mx) == 1
