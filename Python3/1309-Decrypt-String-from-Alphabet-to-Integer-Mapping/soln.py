class Solution:
    def freqAlphabets(self, s: str) -> str:
        chars = string.ascii_lowercase
        m = dict(zip('123456789', chars[:9]))
        m.update(dict(zip(['{}#'.format(val) for val in range(10, 27)], chars[9:])))
        n = len(s)
        ans = []
        i = 0
        while i < n:
            if i + 2 < n and s[i + 2] == '#':
                ans.append(m[s[i:i + 3]])
                i = i + 3
            else:
                ans.append(m[s[i:i + 1]])
                i = i + 1
        return ''.join(ans)
