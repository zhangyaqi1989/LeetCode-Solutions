class Solution:
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        def count(i, j):
            cnt = 0
            while i >= 0 and j < len(s) and s[i] == s[j]:
                cnt += 1
                i, j = i - 1, j + 1
            return cnt
        ans = 0
        for i in range(len(s)):
            for l, r in ((i, i), (i, i + 1)):
                ans += count(l, r)
        return ans