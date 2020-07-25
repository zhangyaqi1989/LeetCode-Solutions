class Solution:
    def numSplits(self, s: str) -> int:
        lefts = []
        seen = set()
        for ch in s:
            seen.add(ch)
            lefts.append(len(seen))
        seen.clear()
        n = len(s)
        rights = [0] * n
        for i in reversed(range(n)):
            seen.add(s[i])
            rights[i] = len(seen)
        ans = 0
        for i in range(n - 1):
            if lefts[i] == rights[i + 1]:
                ans += 1
        return ans
