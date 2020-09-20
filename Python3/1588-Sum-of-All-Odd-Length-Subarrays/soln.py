class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        pres = [0]
        for num in arr:
            pres.append(pres[-1] + num)
        sz = 1
        n = len(arr)
        ans = 0
        while sz <= n:
            i = 0
            while i + sz <= n:
                ans += pres[i + sz] - pres[i]
                i += 1
            sz += 2
        return ans
