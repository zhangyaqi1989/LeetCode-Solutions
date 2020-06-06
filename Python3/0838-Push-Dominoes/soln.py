class Solution:
    def pushDominoes(self, d):
        """
        :type dominoes: str
        :rtype: str
        """
        d = 'L' + d + 'R'
        i = 0
        ans = []
        for j in range(1, len(d)):
            if d[j] == '.': continue
            length = j - i - 1
            if i: ans.append(d[i])
            if d[i] == d[j]: ans.append(d[i] * length)
            elif d[i] == 'L' and d[j] == 'R': ans.append('.' * length)
            else: ans.append('R' * (length // 2) + '.' * (length & 1) + 'L' * (length // 2))
            i = j
        return ''.join(ans)