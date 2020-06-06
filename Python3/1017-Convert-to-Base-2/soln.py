class Solution:
    def baseNeg2(self, N: int) -> str:
        if N == 0:
            return "0"
        ans = ""
        while N != 0:
            r = N % (-2)
            N //= (-2)
            if r < 0:
                r += 2
                N += 1
            ans = str(r) + ans
        return ans
