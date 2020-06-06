class Solution:
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        ans = []
        for row in A:
            temp = row[::-1]
            ans.append([1 - val for val in temp])
        return ans