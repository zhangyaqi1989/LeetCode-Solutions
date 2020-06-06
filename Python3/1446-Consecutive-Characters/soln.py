class Solution:
    def maxPower(self, s: str) -> int:
        return max(len(list(g)) for ch, g in itertools.groupby(s))
