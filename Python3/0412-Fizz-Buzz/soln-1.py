class Solution:
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        return ["Fizz" * (x % 3 == 0) + "Buzz" * (x % 5 == 0) or str(x) for x in range(1, n + 1)]