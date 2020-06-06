class Solution:
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        ugly = [1]
        indexes = [0] * len(primes)
        while n > 1:
            for i in range(len(primes)):
                while ugly[indexes[i]] * primes[i] <= ugly[-1]: indexes[i] += 1
            ugly.append(min(primes[i] * ugly[val] for i, val in enumerate(indexes)))
            n -= 1
        return ugly[-1]