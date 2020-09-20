class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        # len(s) <= 16, only lower_case
        n = len(s)
        mx = 1
        m = n - 1
        total = (1 << m)
        state = 0
        for state in range(total):
            seen = set()
            lo = 0
            for i in range(m + 1):
                if state & (1 << i):
                    token = s[lo:i + 1]
                    if token in seen:
                        break
                    else:
                        seen.add(token)
                    lo = i + 1
            else:
                token = s[lo:n]
                if token not in seen:
                    seen.add(token)
                    mx = max(len(seen), mx)
        return mx
