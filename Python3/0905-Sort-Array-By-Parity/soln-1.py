class Solution:
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        return [num for num in A if not (num & 1)] + [num for num in A if num & 1]