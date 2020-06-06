class Solution:
    def baseNeg2(self, N: int) -> str:
        if N == 0:
            return "0"
        nums = []
        while N != 0:
            r = N % (-2)
            N //= (-2)
            if r < 0:
                r += 2
                N += 1
            nums.append(r)
        return ''.join(map(str, nums[::-1]))
