class Solution:
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        flag = 0
        for a, b in zip(A, A[1:]):
            if a == b: continue
            if flag and (b - a) * flag < 0:
                return False
            else:
                flag = 1 if b > a else -1
        return True