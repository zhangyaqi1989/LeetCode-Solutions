class Solution:
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        ans = 0
        for lst in zip(*A):
            if not all(a <= b for a, b in zip(lst, lst[1:])):
                ans += 1
        return ans