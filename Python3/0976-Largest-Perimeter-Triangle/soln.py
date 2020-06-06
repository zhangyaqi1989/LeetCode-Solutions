class Solution:
    def largestPerimeter(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        A = sorted(A)
        ans = 0
        for i in range(2, len(A)):
            if A[i - 1] + A[i - 2] > A[i]:
                ans = max(ans, A[i - 1] + A[i - 2] + A[i])
        return ans
