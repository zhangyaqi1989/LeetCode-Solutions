class Solution:
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        return [bin(x).count('1') for x in range(num + 1)]