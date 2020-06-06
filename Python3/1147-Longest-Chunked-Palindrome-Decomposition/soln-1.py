class Solution:
    def longestDecomposition(self, text: str) -> int:
        def helper(lo, hi):
            if lo < hi:
                for sz in range(1, (hi - lo + 1) // 2 + 1):
                    left = text[lo : lo + sz]
                    right = text[hi - sz + 1: hi + 1]
                    if left == right:
                        return 2 + helper(lo + sz, hi - sz);
                return 1
            elif lo == hi:
                return 1
            else:
                return 0
        return helper(0, len(text) - 1)
