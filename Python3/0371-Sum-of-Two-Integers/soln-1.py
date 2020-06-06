import statistics
class Solution:
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        return int(statistics.mean((a, b)) * 2)
