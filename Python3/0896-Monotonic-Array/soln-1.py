class Solution:
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        inc = 0
        for i in range(len(A) - 1):
            a, b = A[i], A[i + 1]
            if A[i] != A[i + 1]:
                
                if (inc == 1 and A[i + 1] < A[i]) or (inc == -1 and A[i + 1] > A[i]):
                    return False
                elif inc == 0:
                    inc = 1 if A[i + 1] > A[i] else -1
        return True