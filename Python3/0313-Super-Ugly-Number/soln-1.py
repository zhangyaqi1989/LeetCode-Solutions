class Solution:
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        uglies = [1]
        pq = [(prime, 0, prime) for prime in primes]
        heapq.heapify(pq)
        while len(uglies) < n:
            val, i, factor = heapq.heappop(pq)
            if val > uglies[-1]:    
                uglies.append(val)
            heapq.heappush(pq, (uglies[i + 1] * factor, i + 1, factor))
        return uglies[-1]