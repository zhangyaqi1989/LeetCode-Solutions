class Solution:
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        # longest substring
        for ch in set(s):
            if s.count(ch) < k:
                return max(self.longestSubstring(t, k) for t in s.split(ch))
        return len(s)