class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        def valid(num):
            return all(digit != 0 and num % digit == 0 for digit in map(int, str(num)))
        return [num for num in range(left, right + 1) if valid(num)]