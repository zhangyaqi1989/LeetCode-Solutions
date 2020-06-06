class Solution:
    def partitionDisjoint(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        ans = 0
        mx = A[0]
        cur_mx = A[0]
        for i, num in enumerate(A[1:], 1):
            if num < cur_mx:
                ans = i
                cur_mx = mx
            elif num > mx:
                mx = num
        return ans + 1