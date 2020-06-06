class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        acc = 0
        seen = {0 : -1}
        mx_len = 0
        for i, h in enumerate(hours):
            if h > 8:
                acc += 1
            else:
                acc -= 1
            if acc > 0:
                mx_len = i + 1
            if acc not in seen:
                seen[acc] = i
            if (acc - 1) in seen:
                mx_len = max(mx_len, i - seen[acc - 1])
        return mx_len
