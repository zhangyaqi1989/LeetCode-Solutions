class Solution:
    def beautifulArray(self, N):
        """
        :type N: int
        :rtype: List[int]
        """
        return sorted(range(1, N + 1), key=lambda x : format(x, 'b')[::-1])
