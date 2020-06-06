class Solution:
    def isStrobogrammatic(self, num):
        """
        :type num: str
        :rtype: bool
        """
        # 11, 00, 69, 96, 88,
        return all((num[i] + num[~i]) in ('00', '11', '69', '96', '88') for i in range((len(num) + 1)//2))