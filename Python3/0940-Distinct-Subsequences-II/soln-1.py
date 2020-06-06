class Solution:
    def distinctSubseqII(self, S: str) -> int:
        mod = 1000000007
        end = [0] * 26
        for c in S:
            end[ord(c) - 97] = (sum(end) + 1) % mod
        return sum(end) % mod
