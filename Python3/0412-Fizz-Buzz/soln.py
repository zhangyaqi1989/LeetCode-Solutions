class Solution:
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        # 3: Fizz, 5: Buzz, 15: FizzBuzz
        def fb(num):
            res = ['', 'Fizz'][num % 3 == 0] + ['', 'Buzz'][num % 5 == 0]
            return res if res else str(num)
        return list(map(fb, range(1, n + 1)))