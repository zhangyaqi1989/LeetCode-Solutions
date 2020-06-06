# this is trick :-)
class Solution:
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        try:
            x = float(s)
            return True
        except:
            return False
