class Solution:
    def longestAwesome(self, s: str) -> int:
        ans = 1
        code = 0
        seen = {0 : -1}
        for i, ch in enumerate(s):
            idx = ord(ch) - ord('0')
            code ^= (1 << idx)
            ans = max(ans, i - seen.get(code, i))
            for j in range(10):
                if (code & (1 << j)):
                    temp_code = code - (1 << j)
                    ans = max(ans, i - seen.get(temp_code, i))
                else:
                    temp_code = code + (1 << j)
                    ans = max(ans, i - seen.get(temp_code, i))
            if code not in seen:
                seen[code] = i
        return ans
