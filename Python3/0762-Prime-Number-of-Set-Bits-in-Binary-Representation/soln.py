class Solution:
    def countPrimeSetBits(self, L, R):
        """
        :type L: int
        :type R: int
        :rtype: int
        """
        r = int(math.log2(R))
        def is_prime(num):
            return all(num % factor != 0 for factor in range(2, int(math.sqrt(num)) + 1))
        primes = list(map(is_prime, range(r + 1)))
        primes[:2] = [False] * 2
        return sum(primes[bin(num).count('1')] for num in range(L, R + 1))    