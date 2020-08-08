class Solution:
    def longestAwesome(self, s: str) -> int:
        ans = 1
        code = 0
        seen = [math.inf] * (1 << 10)
        seen[0] = -1
        for i, ch in enumerate(s):
            idx = ord(ch) - ord('0')
            code ^= (1 << idx)
            ans = max(ans, i - seen[code])
            for j in range(10):
                temp_code = code ^ (1 << j)
                ans = max(ans, i - seen[temp_code])
            if seen[code] == math.inf:
                seen[code] = i
        return ans
