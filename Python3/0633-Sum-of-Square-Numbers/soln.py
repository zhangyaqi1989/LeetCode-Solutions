class Solution:
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        squares = set(num * num for num in range(int(math.sqrt(c)) + 1))
        return any(c - num in squares for num in squares) 
