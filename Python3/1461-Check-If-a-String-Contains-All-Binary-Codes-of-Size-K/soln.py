class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        seen = [0] * (1 << k)
        num = 0
        unit = 1 << (k)
        for i, d in enumerate(map(int, s)):
            num = num * 2 + d
            if i - k >= 0:
                if s[i - k] == '1':
                    num -= unit
            if i >= k - 1:
                seen[num] = 1
        return all(num == 1 for num in seen)
