class Solution:
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2:
            return 0
        primes = [0, 0]  + [1] * (n - 2)
        i = 2
        while i < n:
            if primes[i]:
                primes[2*i:n:i] = [0] * len(primes[2*i:n:i])
            i += 1
        return sum(primes)