from functools import lru_cache
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        words = set(wordDict)
        @lru_cache(None)
        def helper(lo):
            if lo == len(s):
                return [[]]
            ans = []
            for i in range(lo + 1, len(s) + 1):
                word = s[lo:i]
                if word in words:
                    tail = helper(i)
                    if tail:
                        ans.extend([[word] + item for item in tail])
            return ans
        return [' '.join(item) for item in helper(0)]
