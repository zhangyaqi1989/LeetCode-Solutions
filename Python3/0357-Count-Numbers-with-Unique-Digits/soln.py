import functools
class Solution:
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        def number_of_unique(n):
            "Count number of numbers with unique Digits."
            if n > 10:
                return 0
            elif n == 1:
                return 10
            else:
                lst = [9, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
                return functools.reduce(operator.mul, lst[:n])
        if n == 0:
            return 1
        return sum(number_of_unique(i) for i in range(1, n + 1))
