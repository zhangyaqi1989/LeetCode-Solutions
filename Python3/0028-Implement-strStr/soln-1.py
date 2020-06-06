class Solution:
    def strStr(self, T: str, P: str) -> int:
        def compute_fail_arr(P):
            m = len(P)
            fail = [0] * m
            j = 1
            k = 0
            while j < m:
                if P[j] == P[k]:
                    fail[j] = k + 1
                    j += 1
                    k += 1
                elif k > 0:
                    k = fail[k - 1]
                else:
                    j += 1
            return fail
        n, m = len(T), len(P)
        if m == 0:
            return 0
        fail = compute_fail_arr(P)
        j = 0
        k = 0
        while j < n:
            if T[j] == P[k]:
                if k == m - 1:
                    return j - m + 1
                j += 1
                k += 1
            elif k > 0:
                k = fail[k - 1]
            else:
                j += 1
        return -1
