class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # longest substring without repeating char
        seen = {}
        left, ans = 0, 0
        for idx, ch in enumerate(s):
            if ch in seen:
                left = max(left, seen[ch])
            seen[ch] = idx + 1
            ans = max(ans, idx - left + 1)
        return ans