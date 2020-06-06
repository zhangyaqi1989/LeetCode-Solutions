class Solution:
    def minFlipsMonoIncr(self, S):
        """
        :type S: str
        :rtype: int
        """
        # try different idxes
        # need to record the left ones and right zeros
        nzeros = S.count('0')
        ones, zeros = [0], [nzeros]
        for ch in S:
            ones.append(ones[-1] + (ch == '1'))
            nzeros -= (ch == '0')
            zeros.append(nzeros)
        return min(zeros[i] + ones[i] for i in range(len(S) + 1))