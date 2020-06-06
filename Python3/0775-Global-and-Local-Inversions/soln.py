class Solution:
    def isIdealPermutation(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        mx = -math.inf
        for i in range(len(A) - 2):
            mx = max(mx, A[i])
            if mx > A[i + 2]:
                return False
        return True
