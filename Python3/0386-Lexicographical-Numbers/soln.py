class Solution:
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        iters = []
        i = 1
        while 10 ** (i - 1) <= n:
            iters.append(range(10 ** (i - 1), min(n + 1, 10 ** (i))))
            i += 1
        merged = heapq.merge(*iters, key=str)
        return list(itertools.islice(merged, n))
