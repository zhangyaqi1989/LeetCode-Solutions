class Solution:
    def uniqueLetterString(self, S):
        """
        :type S: str
        :rtype: int
        """
        idxes = {ch : (-1, -1) for ch in string.ascii_uppercase}
        ans = 0
        n = len(S)
        for idx, ch in enumerate(S):
            i, j = idxes[ch]
            ans += (idx - j) * (j - i)
            idxes[ch] = j, idx
        for (i, j) in idxes.values():
            ans += (j - i) * (n - j)
        return ans % (10**9 + 7)
