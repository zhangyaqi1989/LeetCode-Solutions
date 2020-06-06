class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        func = lambda x : sum(int(ch) ** 2 for ch in str(x))
        seen = set()
        while True:
            if n == 1:
                return True
            if n in seen:
                return False
            seen.add(n)
            n = func(n)