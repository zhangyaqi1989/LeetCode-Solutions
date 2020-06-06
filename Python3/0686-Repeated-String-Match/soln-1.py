class Solution:
    def repeatedStringMatch(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        t = (len(B) + len(A) - 1) // len(A)
        return t * (B in A * t) or (t + 1) * (B in A * (t + 1)) or -1