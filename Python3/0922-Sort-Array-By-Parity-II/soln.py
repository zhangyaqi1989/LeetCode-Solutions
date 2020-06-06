class Solution:
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        odds = [num for num in A if num & 1]
        evens = [num for num in A if num & 1 == 0]
        A[::2], A[1::2] = evens, odds
        return A
