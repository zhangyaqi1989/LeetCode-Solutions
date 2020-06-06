class Solution:
    def shortestSubarray(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        n = len(A)
        acc = [0] + list(itertools.accumulate(A))
        dq = collections.deque()
        res = n + 1
        for i in range(n + 1):
            while dq and acc[i] - acc[dq[0]] >= K:
                res = min(res, i - dq.popleft())
            while dq and acc[i] <= acc[dq[-1]]:
                dq.pop()
            dq.append(i)
        return res if res != n + 1 else -1
