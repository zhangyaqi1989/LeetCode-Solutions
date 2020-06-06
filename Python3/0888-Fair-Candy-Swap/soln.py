class Solution:
    def fairCandySwap(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        sb = set(B)
        diff = (sum(B) - sum(A)) // 2
        for num in A:
            if num + diff in sb:
                return num, num + diff