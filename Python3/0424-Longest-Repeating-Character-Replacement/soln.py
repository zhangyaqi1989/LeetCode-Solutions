class Solution:
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        max_len, res, counter = 0, 0, collections.Counter()
        for i, ch in enumerate(s):
            counter[ch] += 1
            max_len = max(max_len, counter[ch])
            if res - max_len < k: res += 1
            else: counter[s[i - res]] -= 1
        return res