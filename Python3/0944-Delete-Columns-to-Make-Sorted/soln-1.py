class Solution:
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        return sum(any(lst[i + 1] < lst[i] for i in range(len(lst) - 1)) for lst in zip(*A))