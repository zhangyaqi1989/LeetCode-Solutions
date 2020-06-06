class Solution(object):
    def isStrobogrammatic(self, num):
        """
        :type num: str
        :rtype: bool
        """
        l, r = 0, len(num) - 1
        pairs = {'00', '88', '11', '69', '96'}
        while l <= r:
            if num[l] + num[r] not in pairs:
                return False
            l += 1
            r -= 1
        return True