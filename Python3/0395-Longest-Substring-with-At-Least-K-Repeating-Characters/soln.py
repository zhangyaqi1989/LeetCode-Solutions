class Solution:
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        # longest substring
        counter = collections.Counter(s)
        for ch in counter:
            if counter[ch] < k:
                return max(self.longestSubstring(t, k) for t in s.split(ch))
        return len(s)