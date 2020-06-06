class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s):
        """
        :type s: str
        :rtype: int
        """
        # sliding window
        counter = collections.Counter()
        i, ans = 0, 0
        for j, ch in enumerate(s):
            counter[ch] += 1
            while len(counter) > 2:
                counter[s[i]] -= 1
                if counter[s[i]] == 0:
                    counter.pop(s[i])
                i += 1
            ans = max(ans, j - i + 1)
        return ans