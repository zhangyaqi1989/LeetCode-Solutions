class Solution:
    def primePalindrome(self, N):
        """
        :type N: int
        :rtype: int
        """
        def is_prime(num):
            "Check if num is prime."
            if num < 2 or num % 2 == 0:
                return num == 2
            for factor in range(3, int(num ** 0.5) + 1, 2):
                if num % factor == 0:
                    return False
            return True
        if 8 <= N <= 11:
            return 11
        for x in range(10 ** (len(str(N)) // 2), 10 ** 5):
            y = int(str(x) + str(x)[-2::-1])
            if y >= N and is_prime(y):
                return y
