class Solution:
    def superpalindromesInRange(self, L, R):
        """
        :type L: str
        :type R: str
        :rtype: int
        """
        R = int(R)
        L = int(L)
        sqrts = ['11', '22']
        for s in sqrts:
            for ch in ('0', '1', '2'):
                sqrts.append(s[:len(s) // 2] + ch + s[len(s) // 2:])
            if int(s) ** 2 > R:
                break
        sqrts.extend(['1', '2', '3'])
        return sum(L <= int(s) <= R and s == s[::-1] for s in map(lambda x : str(int(x) ** 2), sqrts))