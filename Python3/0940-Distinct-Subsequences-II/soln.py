class Solution:
    def distinctSubseqII(self, S):
        """
        :type S: str
        :rtype: int
        """
        end = [0] * 26
        for c in S:
            end[ord(c) - 97] = sum(end) + 1
        return sum(end) % (10 ** 9 + 7)
