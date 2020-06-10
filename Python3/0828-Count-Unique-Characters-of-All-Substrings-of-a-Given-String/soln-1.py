class Solution:
    def uniqueLetterString(self, S: str) -> int:
        idxes = {ch : (-1, -1) for ch in string.ascii_uppercase}
        ans = 0
        for idx, ch in enumerate(S):
            i, j = idxes[ch]
            ans += (j - i) * (idx - j)
            idxes[ch] = j, idx
        for i, j in idxes.values():
            ans += (j - i) * (len(S) - j)
        return ans % (int(1e9) + 7)
