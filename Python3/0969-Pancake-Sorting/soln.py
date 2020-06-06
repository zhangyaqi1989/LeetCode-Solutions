class Solution:
    def pancakeSort(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        if not A:
            return []
        mx = max(A)
        if A[-1] == mx:
            return self.pancakeSort(A[:-1])
        else:
            idx = A.index(mx)
            A[:idx + 1] = A[:idx + 1][::-1]
            A = A[::-1]
            n = len(A)
            return [idx + 1, n] + self.pancakeSort(A[:-1])
