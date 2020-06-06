class Solution:
    def superpalindromesInRange(self, L: str, R: str) -> int:
        def isPalin(s):
            return s == s[::-1]
        cands = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
        for i in range(1, 10000):
            s = str(i)
            rs = s[::-1]
            cands.append(s + rs)
            for j in range(10):
                cands.append(s + str(j) + rs)
        cands = list(map(int, cands))
        cands.sort()
        cnt = 0
        L, R = int(L), int(R)
        for cand in cands:
            cand *= cand
            if cand < L:
                continue
            if cand > R:
                break
            if isPalin(str(cand)):
                cnt += 1
        return cnt
