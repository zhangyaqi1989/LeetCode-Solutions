class Solution:
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        s = bin(num)[2:] 
        return int((''.join(['0', '1'][ch == '0'] for ch in s)), 2)