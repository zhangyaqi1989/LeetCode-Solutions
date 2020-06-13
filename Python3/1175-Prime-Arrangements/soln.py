class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        def is_prime(num):
            return num > 1 and all(num % f != 0 for f in range(2, int(math.sqrt(num)) + 1))
        nprimes = sum(is_prime(num) for num in range(1, n + 1))
        return math.factorial(nprimes) * (math.factorial(n - nprimes)) % 1000000007
