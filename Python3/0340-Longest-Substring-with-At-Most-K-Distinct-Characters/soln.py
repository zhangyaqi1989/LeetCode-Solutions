class Solution:
    def lengthOfLongestSubstringKDistinct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        # longest substring T that contains at most k distinct characters
        ans, i= 0, 0
        d = collections.Counter()
        for j, ch in enumerate(s):
            d[ch] += 1
            while len(d) > k:
                d[s[i]] -= 1
                if d[s[i]] == 0:
                    d.pop(s[i])
                i += 1
            ans = max(ans, j - i + 1)
        return ans