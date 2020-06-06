class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        m = dict(zip(('I', 'V', 'X', 'L', 'C', 'D', 'M'), (1, 5, 10, 50, 100, 500, 1000)))
        res = 0
        for idx, ch in enumerate(s):
            res += m[ch]
            if idx > 0 and m[ch] > m[s[idx - 1]]:
                res -= 2 * m[s[idx - 1]]
        return res