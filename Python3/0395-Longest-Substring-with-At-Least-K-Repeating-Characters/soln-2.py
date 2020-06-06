class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        counter = collections.Counter(s)
        for ch, cnt in counter.items():
            if cnt < k:
                return max(self.longestSubstring(sub, k) for sub in s.split(ch))
        return len(s)
