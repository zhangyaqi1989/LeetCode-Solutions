class Solution:
    def maxWidthRamp(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        idxes = sorted(range(len(A)), key=lambda i : A[i])
        mn_idx = math.inf
        mx_width = 0
        for idx in idxes:
            mx_width = max(mx_width, idx - mn_idx)
            mn_idx = min(mn_idx, idx)
        return mx_width
