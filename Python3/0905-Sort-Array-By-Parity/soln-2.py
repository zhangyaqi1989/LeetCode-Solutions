class Solution:
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        ans = [None] * len(A)
        i, j = 0, len(A) - 1
        for num in A:
            if num & 1:
                ans[j] = num
                j -= 1
            else:
                ans[i] = num
                i += 1
        return ans