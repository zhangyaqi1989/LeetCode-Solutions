class Solution:
    def subarrayBitwiseORs(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        res, cur = set(), set()
        for x in A:
            cur = {x | y for y in cur} | {x}
            res |= cur
        return len(res)
