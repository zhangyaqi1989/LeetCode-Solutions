class Solution:
    def partitionDisjoint(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        # max of left <= min of right
        lefts = [A[0]]
        for i in range(1, len(A) - 1):
            lefts.append(max(A[i], lefts[-1]))
        rights = [A[-1]]
        for j in range(len(A) - 2, 0, -1):
            rights.append(min(A[j], rights[-1]))
        for idx, (left_mx, right_mn) in enumerate(zip(lefts, rights[::-1]), 1):
            if left_mx <= right_mn: return idx