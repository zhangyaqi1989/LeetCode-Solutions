from functools import lru_cache
class Solution:
    def countPalindromicSubsequences(self, S: str) -> int:
        @lru_cache(None)
        def dfs(S, start, end):
            cnt = 0
            for ch in 'abcd':
                i = S.find(ch, start, end)
                j = S.rfind(ch, start, end)
                if i != -1 and j != -1:
                    cnt += dfs(S, i + 1, j) + (2 if i != j else 1)
            return cnt
        return dfs(S, 0, len(S)) % (10**9 + 7)
