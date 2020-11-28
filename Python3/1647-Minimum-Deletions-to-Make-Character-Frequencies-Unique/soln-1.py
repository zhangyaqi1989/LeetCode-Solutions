class Solution:
    def minDeletions(self, s: str) -> int:
        counter = collections.Counter(s)
        counts = list(counter.values())
        counts.sort(reverse=True)
        target = counts[0]
        ans = 0
        for cnt in counts:
            if cnt >= target:
                ans += cnt - target
                cnt = target
            target = max(0, cnt - 1)
        return ans
