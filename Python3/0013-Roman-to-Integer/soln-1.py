class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = {'I' : 1, 'V' : 5, 'X' : 10, 'L' : 50, 'C' : 100, 'D' : 500, 'M' : 1000}
        ans = d[s[0]]
        for i in range(1, len(s)):
            ans += d[s[i]]
            if d[s[i]] > d[s[i - 1]]:
                ans -= 2 * d[s[i - 1]]
        return ans