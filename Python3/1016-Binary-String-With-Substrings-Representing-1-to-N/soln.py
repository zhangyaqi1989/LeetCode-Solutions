class Solution:
    def queryString(self, S: str, N: int) -> bool:
        n = len(bin(N)) - 2
        s_set = set()
        ns = len(S)
        if ns * n < N:
            return False
        for length in range(1, n + 1):
            for i in range(ns + 1 - length):
                s_set.add(int(S[i:i + length], 2))
        # ns + ns - 1 + ns - 2 + ns - 3 ...
        if len(s_set) < N:
            return False
        return s_set >= set(range(1, N + 1))
