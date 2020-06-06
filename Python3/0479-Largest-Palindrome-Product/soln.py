class Solution:
    def largestPalindrome(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 9
        elif n == 2:
            return 987
        else:
            for i in range(2, 9 * 10 ** (n - 1)):
                hi = (10 ** n) - i
                lo = int(str(hi)[::-1])
                if i ** 2 - 4 * lo < 0:
                    continue
                if (i ** 2 - 4 * lo) ** 0.5 == int((i ** 2 - 4 * lo) ** 0.5):
                    return (lo + 10 ** n * (10 ** n - i)) % 1337
