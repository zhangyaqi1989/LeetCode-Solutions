class Solution:
    def beautifulArray(self, N):
        """
        :type N: int
        :rtype: List[int]
        """
        lst = [1]
        while len(lst) < N:
            lst = [2 * x - 1 for x in lst] + [2 * x for x in lst]
        return [x for x in lst if x <= N]
