class Solution:
    def longestAwesome(self, s: str) -> int:
        ans = 1
        cur = [0] * 10
        seen = {0 : -1}
        for i, ch in enumerate(s):
            idx = ord(ch) - ord('0')
            cur[idx] += 1
            if cur[idx] >= 2:
                cur[idx] -= 2
            code = 0
            cnt = 0
            for j in range(10):
                if cur[j]:
                    cnt += 1
                    code |= 1 << j
            if code in seen:
                ans = max(ans, i - seen[code])
            for j in range(10):
                if cur[j]:
                    temp_code = code - (1 << j)
                    if temp_code in seen:
                        ans = max(ans, i - seen[temp_code])
                else:
                    temp_code = code + (1 << j)
                    if temp_code in seen:
                        ans = max(ans, i - seen[temp_code])
            if code not in seen:
                seen[code] = i
        return ans
