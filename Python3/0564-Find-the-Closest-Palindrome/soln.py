class Solution:
    def nearestPalindromic(self, n):
        """
        :type n: str
        :rtype: str
        """
        length = len(n)
        half = int(n[:(length + 1) // 2])
        nums = [half, half + 1, half - 1]
        cands = []
        for num in nums:
            s = str(num)
            s = s + s[:length//2][::-1]
            cands.append(int(s))
        cands.extend([10 ** t + dx for t in (length, length - 1) for dx in (-1, 1)])
        n = int(n)
        return str(min([cand for cand in cands if cand >= 0 and cand != n], key=lambda x : (abs(n - x), x)))
