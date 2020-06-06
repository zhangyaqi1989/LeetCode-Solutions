class Solution(object):
    def minIncrementForUnique(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        # 1 2 2 3 4 5 6
        cnt = 0
        low = -1
        for num in sorted(A):
            if num > low:
                low = num
            else: # low >= num
                low += 1
                cnt += low - num
        return cnt
