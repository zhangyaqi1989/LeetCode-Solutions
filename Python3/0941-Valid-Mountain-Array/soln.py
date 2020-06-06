class Solution:
    def validMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        if len(A) < 3:
            return False
        max_idx, max_value = 0, float('-inf')
        for i, num in enumerate(A):
            if num > max_value:
                max_value = num
                max_idx = i
        return 0 < max_idx < len(A) - 1 and all(a < b for a, b in zip(A[:max_idx], A[1:max_idx])) and all(a > b for a, b in zip(A[max_idx:], A[max_idx + 1:]))     