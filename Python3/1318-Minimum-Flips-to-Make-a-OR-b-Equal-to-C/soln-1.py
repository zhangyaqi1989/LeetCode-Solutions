class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        cnt = 0
        for i in range(32):
            ci = 1 if (c & (1 << i)) else 0
            ai = 1 if (a & (1 << i)) else 0
            bi = 1 if (b & (1 << i)) else 0
            if ci == 0:
                cnt += ai != 0
                cnt += bi != 0
            else:
                if ai == 0 and bi == 0:
                    cnt += 1
        return cnt
