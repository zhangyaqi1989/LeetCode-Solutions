class Solution:
    def maxSubarraySumCircular(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        cur_mn, mn, cur_mx, mx, total = A[0], A[0], A[0], A[0], A[0]
        for num in A[1:]:
            cur_mn = min(cur_mn + num, num)
            mn = min(mn, cur_mn)
            cur_mx = max(cur_mx + num, num)
            mx = max(mx, cur_mx)
            total += num
        return max(mx, total - mn) if mx >= 0 else mx
        