class Solution:
    def minSwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        swap, no_swap = 1, 0
        n = len(A)
        for i in range(n - 1):
            temp_no_swap = temp_swap = math.inf
            if A[i] < A[i + 1] and B[i] < B[i + 1]:
                temp_no_swap = min(temp_no_swap, no_swap)
                temp_swap = min(temp_swap, swap + 1)
            if A[i] < B[i + 1] and B[i] < A[i + 1]:
                temp_no_swap = min(temp_no_swap, swap)
                temp_swap = min(temp_swap, no_swap + 1)
            no_swap, swap = temp_no_swap, temp_swap
        return min(no_swap, swap)
